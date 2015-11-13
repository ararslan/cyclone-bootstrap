/* A basic mark-sweep GC
   As of now, the GC code is based off the implementation from chibi scheme

 Goals of this project:
 - write algorithms
 - add test cases
 - integrate with types
 - integrate with cyclone
 - extend to tri-color marking an on-the-fly collection
 - etc...
 */

#include "cyclone/types.h"

////////////////////
// Global variables

// Note: will need to use atomics and/or locking to access any
// variables shared between threads
static int        gc_color_mark = 2; // Black, is swapped during GC
static int        gc_color_clear = 3; // White, is swapped during GC
//static const int  gc_color_grey = 4; // TODO: appears unused, clean up
// unfortunately this had to be split up; const colors are located in types.h

static int gc_status_col = STATUS_SYNC1;
static int gc_stage = STAGE_CLEAR_OR_MARKING;

// Does not need sync, only used by collector thread
static void **mark_stack = NULL;
static int mark_stack_len = 128;
static int mark_stack_i = 0;

// Lock to protect the heap from concurrent modifications
static pthread_mutex_t heap_lock;

// Data for each individual mutator thread
static gc_thread_data **Cyc_mutators;
static int Cyc_num_mutators;

/////////////
// Functions

// Perform one-time initialization before mutators can be executed
void gc_init_mutators()
{
  // TODO: alloca this using a vpbuffer, or maybe another type of data structure??
  // Will need this list for later use, but only by the collector thread. so it would be
  // nice if there was a way to allocate mutators that avoids expensive synchronization...
  // need to think on this when adding thread support, after upgrading the collector
  Cyc_num_mutators = 1; 
  Cyc_mutators = calloc(Cyc_num_mutators, sizeof(gc_thread_data *));

  // Here is as good a place as any to do this...
  if (pthread_mutex_init(&(heap_lock), NULL) != 0) {
    fprintf(stderr, "Unable to initialize heap_lock mutex\n");
    exit(1);
  }
}

// Add data for a new mutator
void gc_add_mutator(gc_thread_data *thd)
{
  // TODO: need to sync access to these static variables. both here and
  // elsewhere in the module!!
  int i;
  for (i = 0; i < Cyc_num_mutators; i++) {
    if (!Cyc_mutators[i]) {
      Cyc_mutators[i] = thd;
      return;
    }
  }
  // TODO: unable to create any more mutators. what to do???
  fprintf(stderr, "Unable to create a new thread, exiting\n");
  exit(1);
}

gc_heap *gc_heap_create(size_t size, size_t max_size, size_t chunk_size)
{
  gc_free_list *free, *next;
  gc_heap *h;
  // TODO: mmap?
  h = malloc(gc_heap_pad_size(size));
  if (!h) return NULL;
  h->size = size;
  h->chunk_size = chunk_size;
  h->max_size = max_size;
//printf("DEBUG h->data addr: %p\n", &(h->data));
  h->data = (char *) gc_heap_align(sizeof(h->data) + (uint)&(h->data)); 
//printf("DEBUG h->data addr: %p\n", h->data);
  h->next = NULL;
  free = h->free_list = (gc_free_list *)h->data;
  next = (gc_free_list *)(((char *) free) + gc_heap_align(gc_free_chunk_size));
  free->size = 0; // First one is just a dummy record
  free->next = next;
  next->size = size - gc_heap_align(gc_free_chunk_size);
  next->next = NULL;
#if GC_DEBUG_PRINTFS
  fprintf(stderr, ("heap: %p-%p data: %p-%p size: %d\n"),
          h, ((char*)h)+gc_heap_pad_size(size), h->data, h->data + size, size);
  fprintf(stderr, ("first: %p end: %p\n"),
          (object)gc_heap_first_block(h), (object)gc_heap_end(h));
  fprintf(stderr, ("free1: %p-%p free2: %p-%p\n"),
          free, ((char*)free)+free->size, next, ((char*)next)+next->size);
#endif
  return h;
}

int gc_grow_heap(gc_heap *h, size_t size, size_t chunk_size)
{
  size_t cur_size, new_size;
  gc_heap *h_last, *h_new;
  pthread_mutex_lock(&heap_lock);
  h_last = gc_heap_last(h);
  cur_size = h_last->size;
  // JAE - For now, just add a new page
  new_size = cur_size; //gc_heap_align(((cur_size > size) ? cur_size : size) * 2);
  h_new = gc_heap_create(new_size, h_last->max_size, chunk_size);
  h_last->next = h_new;
  pthread_mutex_unlock(&heap_lock);
printf("DEBUG - grew heap\n");
  return (h_new != NULL);
}

void *gc_try_alloc(gc_heap *h, size_t size) 
{
  gc_free_list *f1, *f2, *f3;
  pthread_mutex_lock(&heap_lock);
  for (; h; h = h->next) { // All heaps
    // TODO: chunk size (ignoring for now)

    for (f1 = h->free_list, f2 = f1->next; f2; f1 = f2, f2 = f2->next) { // all free in this heap
      if (f2->size >= size) { // Big enough for request
        // TODO: take whole chunk or divide up f2 (using f3)?
        if (f2->size >= (size + gc_heap_align(1) /* min obj size */)) {
          f3 = (gc_free_list *) (((char *)f2) + size);
          f3->size = f2->size - size;
          f3->next = f2->next;
          f1->next = f3;
        } else { /* Take the whole chunk */
          f1->next = f2->next;
        }
        return f2;
      }
    }
  }
  pthread_mutex_unlock(&heap_lock);
  return NULL; 
}

//TODO: need a heap lock.
//lock during - alloc, sweep? but now sweep becomes a stop the world...
// maybe only lock during each individual operation, not for a whole
// sweep or alloc

void *gc_alloc(gc_heap *h, size_t size, int *heap_grown) 
{
  void *result = NULL;
  size_t max_freed = 0, sum_freed = 0, total_size;
  // TODO: check return value, if null (could not alloc) then 
  // run a collection and check how much free space there is. if less
  // the allowed ratio, try growing heap.
  // then try realloc. if cannot alloc now, then throw out of memory error
  size = gc_heap_align(size);
  result = gc_try_alloc(h, size);
  if (!result) {
    // TODO: may want to consider not doing this now, and implementing gc_collect as
    // part of the runtime, since we would have all of the roots, stack args, 
    // etc available there.
//    max_freed = gc_collect(h); TODO: this does not work yet!
//
//    total_size = gc_heap_total_size(h);
//    if (((max_freed < size) ||
//         ((total_size > sum_freed) &&
//          (total_size - sum_freed) > (total_size * 0.75))) // Grow ratio
//        && ((!h->max_size) || (total_size < h->max_size))) {
      gc_grow_heap(h, size, 0);
      *heap_grown = 1;
//    }
    result = gc_try_alloc(h, size);
    if (!result) {
      fprintf(stderr, "out of memory error allocating %d bytes\n", size);
      exit(1); // TODO: throw error???
    }
  }
#if GC_DEBUG_PRINTFS
  fprintf(stdout, "alloc %p size = %d\n", result, size);
#endif
  return result;
}

size_t gc_allocated_bytes(object obj)
{
  tag_type t;
  if (is_value_type(obj))
    return gc_heap_align(1);
  t = type_of(obj); 
  if (t == cons_tag) return gc_heap_align(sizeof(cons_type));
  if (t == macro_tag) return gc_heap_align(sizeof(macro_type));
  if (t == closure0_tag) return gc_heap_align(sizeof(closure0_type));
  if (t == closure1_tag) return gc_heap_align(sizeof(closure1_type));
  if (t == closure2_tag) return gc_heap_align(sizeof(closure2_type));
  if (t == closure3_tag) return gc_heap_align(sizeof(closure3_type));
  if (t == closure4_tag) return gc_heap_align(sizeof(closure4_type));
  if (t == closureN_tag){
    return gc_heap_align(sizeof(closureN_type) + sizeof(object) * ((closureN_type *)obj)->num_elt);
  }
  if (t == vector_tag){
    return gc_heap_align(sizeof(vector_type) + sizeof(object) * ((vector_type *)obj)->num_elt);
  }
  if (t == string_tag){
    return gc_heap_align(sizeof(string_type) + string_len(obj) + 1);
  }
  if (t == integer_tag) return gc_heap_align(sizeof(integer_type));
  if (t == double_tag) return gc_heap_align(sizeof(double_type));
  if (t == port_tag) return gc_heap_align(sizeof(port_type));
  if (t == cvar_tag) return gc_heap_align(sizeof(cvar_type));
  
//#if GC_DEBUG_PRINTFS
  fprintf(stderr, "gc_allocated_bytes: unexpected object %p of type %ld\n", obj, t);
  exit(1);
//#endif
  return 0;
}

gc_heap *gc_heap_last(gc_heap *h)
{
  while (h->next)
    h = h->next;
  return h;
}

size_t gc_heap_total_size(gc_heap *h)
{
  size_t total_size = 0;
  pthread_mutex_lock(&heap_lock);
  while(h) {
    total_size += h->size;
    h = h->next;
  }
  pthread_mutex_unlock(&heap_lock);
  return total_size;
}

//void gc_mark(gc_heap *h, object obj)
//{
//  if (nullp(obj) || is_value_type(obj) || mark(obj))
//    return;
//
//#if GC_DEBUG_PRINTFS
////  fprintf(stdout, "gc_mark %p\n", obj);
//#endif
//  ((list)obj)->hdr.mark = 1;
// // TODO: mark heap saves (??) 
// // could this be a write barrier?
// 
// // Mark objects this one references
//  if (type_of(obj) == cons_tag) {
//    gc_mark(h, car(obj)); 
//    gc_mark(h, cdr(obj)); 
//  } else if (type_of(obj) == closure1_tag) {
//    gc_mark(h, ((closure1) obj)->elt1); 
//  } else if (type_of(obj) == closure2_tag) {
//    gc_mark(h, ((closure2) obj)->elt1); 
//    gc_mark(h, ((closure2) obj)->elt2); 
//  } else if (type_of(obj) == closure3_tag) {
//    gc_mark(h, ((closure3) obj)->elt1); 
//    gc_mark(h, ((closure3) obj)->elt2); 
//    gc_mark(h, ((closure3) obj)->elt3); 
//  } else if (type_of(obj) == closure4_tag) {
//    gc_mark(h, ((closure4) obj)->elt1); 
//    gc_mark(h, ((closure4) obj)->elt2); 
//    gc_mark(h, ((closure4) obj)->elt3); 
//    gc_mark(h, ((closure4) obj)->elt4); 
//  } else if (type_of(obj) == closureN_tag) {
//    int i, n = ((closureN) obj)->num_elt;
//    for (i = 0; i < n; i++) {
//      gc_mark(h, ((closureN) obj)->elts[i]);
//    }
//  } else if (type_of(obj) == vector_tag) {
//    int i, n = ((vector) obj)->num_elt;
//    for (i = 0; i < n; i++) {
//      gc_mark(h, ((vector) obj)->elts[i]);
//    }
//  }
//}

size_t gc_sweep(gc_heap *h, size_t *sum_freed_ptr)
{
  size_t freed, max_freed=0, sum_freed=0, size;
  object p, end;
  gc_free_list *q, *r, *s;

  //
  // Lock the heap to prevent issues with allocations during sweep
  // It sucks to have to use a coarse-grained lock like this, but let's
  // be safe and prevent threading issues right now. Once the new GC
  // works we can go back and try to speed things up (if possible)
  // by using more fine-grained locking. Can also profile to see
  // how much time is even spent sweeping
  //
  pthread_mutex_lock(&heap_lock);
  for (; h; h = h->next) { // All heaps
#if GC_DEBUG_CONCISE_PRINTFS
    fprintf(stdout, "sweep heap %p, size = %d\n", h, h->size);
#endif
    p = gc_heap_first_block(h);
    q = h->free_list;
    end = gc_heap_end(h);
    while (p < end) {
      // find preceding/succeeding free list pointers for p
      for (r = q->next; r && ((char *)r < (char *)p); q=r, r=r->next);

      if ((char *)r == (char *)p) { // this is a free block, skip it
        p = (object) (((char *)p) + r->size);
#if GC_DEBUG_PRINTFS
        fprintf(stdout, "skip free block %p size = %d\n", p, r->size);
#endif
        continue;
      }
      size = gc_heap_align(gc_allocated_bytes(p));
//fprintf(stdout, "check object %p, size = %d\n", p, size);
      
#if GC_DEBUG_CONCISE_PRINTFS
      // DEBUG
      if (!is_object_type(p))
        fprintf(stderr, "sweep: invalid object at %p", p);
      if ((char *)q + q->size > (char *)p)
        fprintf(stderr, "bad size at %p < %p + %u", p, q, q->size);
      if (r && ((char *)p) + size > (char *)r)
        fprintf(stderr, "sweep: bad size at %p + %d > %p", p, size, r);
      // END DEBUG
#endif

      if (mark(p) == gc_color_clear) {
#if GC_DEBUG_PRINTFS
        fprintf(stdout, "sweep: object is not marked %p\n", p);
#endif
        mark(p) = gc_color_blue; // Needed?
        // free p
        sum_freed += size;
        if (((((char *)q) + q->size) == (char *)p) && (q != h->free_list)) {
          /* merge q with p */
          if (r && r->size && ((((char *)p)+size) == (char *)r)) {
            // ... and with r
            q->next = r->next;
            freed = q->size + size + r->size;
            p = (object) (((char *)p) + size + r->size);
          } else {
            freed = q->size + size;
            p = (object) (((char *)p) + size);
          }
          q->size = freed;
        } else {
          s = (gc_free_list *)p;
          if (r && r->size && ((((char *)p) + size) == (char *)r)) {
            // merge p with r
            s->size = size + r->size;
            s->next = r->next;
            q->next = s;
            freed = size + r->size;
          } else {
            s->size = size;
            s->next = r;
            q->next = s;
            freed = size;
          }
          p = (object) (((char *)p) + freed);
        }
        if (freed > max_freed)
          max_freed = freed;
      } else {
#if GC_DEBUG_PRINTFS
//        fprintf(stdout, "sweep: object is marked %p\n", p);
#endif
        p = (object)(((char *)p) + size);
      }
    }
  }
  pthread_mutex_unlock(&heap_lock);
  if (sum_freed_ptr) *sum_freed_ptr = sum_freed;
  return max_freed;
}

void gc_thr_grow_move_buffer(gc_thread_data *d)
{
  if (!d) return;

  if (d->moveBufLen == 0) { // Special case
    d->moveBufLen = 128;
    d->moveBuf = NULL;
  } else {
    d->moveBufLen *= 2;
  }

  d->moveBuf = realloc(d->moveBuf, d->moveBufLen * sizeof(void *));
#if GC_DEBUG_CONCISE_PRINTFS
  printf("grew moveBuffer, len = %d\n", d->moveBufLen);
#endif
}

void gc_thr_add_to_move_buffer(gc_thread_data *d, int *alloci, object obj)
{
  if (*alloci == d->moveBufLen) {
    gc_thr_grow_move_buffer(d);
  }

  d->moveBuf[*alloci] = obj;
  (*alloci)++;
}

// Generic buffer functions
void **vpbuffer_realloc(void **buf, int *len)
{
  return realloc(buf, (*len) * sizeof(void *));
}

void **vpbuffer_add(void **buf, int *len, int i, void *obj)
{
  if (i == *len) {
    *len *= 2;
    buf = vpbuffer_realloc(buf, len);
  }
  buf[i] = obj;
  return buf;
}

void vpbuffer_free(void **buf)
{
  free(buf);
}


// void gc_init()
// {
// }
// END heap definitions


/*
Rough plan for how to implement new GC algorithm. We need to do this in
phases in order to have any hope of getting everything working. Let's prove
the algorithm out, then extend support to multiple mutators if everything
looks good.

PHASE 1 - separation of mutator and collector into separate threads

need to syncronize access (preferably via atomics) for anything shared between the 
collector and mutator threads.

can cooperate be part of a minor gc? in that case, the 
marking could be done as part of allocation

but then what exactly does that mean, to mark gray? because
objects moved to the heap will be set to mark color at that 
point (until collector thread finishes). but would want
objects on the heap referenced by them to be traced, so 
I suppose that is the purpose of the gray, to indicate
those still need to be traced. but need to think this through,
do we need the markbuffer and last read/write? do those make
  sense with mta approach (assume so)???

ONLY CONCERN - what happens if an object on the stack 
has a reference to an object on the heap that is collected?
but how would this happen? collector marks global roots before
telling mutators to go to async, and once mutators go async
any allocations will not be collected. also once collectors go
async they have a chance to markgray, which will include the write
barrier. so given that, is it still possible for an old heap ref to 
sneak into a stack object during the async phase?

more questions on above point:
- figure out how/if after cooperation/async, can a stack object pick
  up a reference to a heap object that will be collected during that GC cycle?
  need to be able to prevent this somehow...

- need to figure out real world use case(s) where this could happen, to try and
  figure out how to address this problem

from my understanding of the paper, the write barrier prevents this. consider, at the
start of async, the mutator's roots, global roots, and anything on the write barrier
have been marked. any new objects will be allocated as marked. that way, anything the
mutator could later access is either marked or will be after tracing. the only exception
is if the mutator changes a reference such that tracing will no longer find an object.
but the write barrier prevents this - during tracing a heap update causes the old
object to be marked as well. so it will eventually be traced, and there should be no
dangling objects after GC completes.

PHASE 2 - multi-threaded mutator (IE, more than one stack thread):

- how does the collector handle stack objects that reference objects from 
  another thread's stack?
  * minor GC will only relocate that thread's objects, so another thread's would not
    be moved. however, if another thread references one of the GC'd thread's
    stack objects, it will now get a forwarding pointer. even worse, what if the
    other thread is blocked and the reference becomes corrupt due to the stack
    longjmp? there are major issues with one thread referencing another thread's
    objects.
  * had considered adding a stack bit to the object header. if we do this and
    initialize it during object creation, a thread could in theory detect
    if an object belongs to another thread. but it might be expensive because
    a read barrier would have to be used to check the object's stack bit and
    address (to see if it is on this heap).
  * alternatively, how would one thread pick up a reference to another one's
    objects? are there any ways to detect these events and deal with them?
    it might be possible to detect such a case and allocate the object on the heap,
    replacing it with a fwd pointer. unfortunately that means we need a read 
    barrier (ick) to handle forwarding pointers in arbitrary places
  * but does that mean we need a fwd pointer to be live for awhile? do we need
    a read barrier to get this to work? obviously we want to avoid a read barrier
    at all costs.
- what are the real costs of allowing forwarding pointers to exist outside of just
  minor GC? assume each runtime primitive would need to be updated to handle the
  case where the obj is a fwd pointer - is it just a matter of each function 
  detecting this and (possibly) calling itself again with the 'real' address?
  obviously that makes the runtime slower due to more checks, but maybe it is
  not *so* bad?
*/

// tri-color GC section, WIP

/////////////////////////////////////////////
// GC functions called by the Mutator threads

// Write barrier for updates to heap-allocated objects
void gc_mut_update(gc_thread_data *thd, object old_obj, object value)
{
  int status = ATOMIC_GET(&gc_status_col),
      stage = ATOMIC_GET(&gc_stage);
  if (thd->gc_status != STATUS_ASYNC) {
    gc_mark_gray(thd, old_obj);
    gc_mark_gray(thd, value);
  } else if (stage == STAGE_TRACING) {
    gc_mark_gray(thd, old_obj);
  }
// TODO: concerned there may be an issue here with a stack object
// having a 'tree' of references that contains heap objects. these
// objects would be skipped and would never be grayed by the current
// code:
//
//  the paper marks both the heap location being written to and the
//  value being written. not sure it makes sense to mark the value 
//  as it will always be on the stack - issue is if any obj's it is
//  referencing are on the heap. this is where that stack bit might
//  come in handy.
//
//  do we want to mark gray immediately during add mutator, or wait
//  until minor GC? YES - I think for mutators we need to mark the
//  object gray immediately. otherwise if we delay until GC, a sweep
//  may have already finished up and freed such an obj that would
//  otherwise not have been freed if we had waited.
//
//  again, only potential issue seems to be if a stack obj could ref
//  something else on the heap - can that happen? I think this can only
//  happen if the heap obj it refs is linked to a root, because stack
//  objs are so short lived??
//
//  also we already know if objects are on the stack due to their color (RED).
//  so can use this to not mark red values. otherwise probably do want
//  to mark the 'y' as well (per paper) to prevent timing issues when we wait
//
// do have some concern though that mark_gray will stop when a stack obj
// is detected, and the code will not examine any refs held by the stack obj.
}

// TODO: still need to handle case where a mutator is blocked
void gc_mut_cooperate(gc_thread_data *thd)
{
  int i, status = ATOMIC_GET(&gc_status_col);
  if (thd->gc_status != status) {
    if (thd->gc_status == STATUS_ASYNC) {
      // Async is done, so clean up old mark data from the last collection
      thd->last_write = 0;
      thd->last_read = 0;
    }
    else if (thd->gc_status == STATUS_SYNC2) {
      // Mark thread "roots"
      gc_mark_gray(thd, thd->gc_cont);
      for (i = 0; i < thd->gc_num_args; i++) {
        gc_mark_gray(thd, thd->gc_args[i]);
      }
      thd->gc_alloc_color = ATOMIC_GET(&gc_color_mark);
    }
    thd->gc_status = status;
  }
}

/////////////////////////////////////////////
// Collector functions

void gc_mark_gray(gc_thread_data *thd, object obj)
{
  // From what I can tell, no other thread would be modifying
  // either object type or mark. Both should be stable once the object is placed
  // into the heap, with the collector being the only thread that changes marks.
  if (is_object_type(obj) && mark(obj) == gc_color_clear) { // TODO: sync??
    // Place marked object in a buffer to avoid repeated scans of the heap.
// TODO:
// Note that ideally this should be a lock-free data structure to make the
// algorithm more efficient. So this code (and the corresponding collector
// trace code) should be converted at some point.
    pthread_mutex_lock(&(thd->lock));
    thd->mark_buffer = vpbuffer_add(thd->mark_buffer, 
                                    &(thd->mark_buffer_len),
                                    thd->last_write,
                                    obj);
    (thd->last_write)++; // Already locked, just do it...
    pthread_mutex_unlock(&(thd->lock));
  }
}

void gc_collector_trace()
{
  gc_thread_data *m;
  int clean = 0, i;
  while (!clean) {
    clean = 1;
    // TODO: need to sync access to mutator int/void data, UNLESS
    // the collector thread is the only one that is using these
    // fields.
    for (i = 0; i < Cyc_num_mutators; i++) {
      m = Cyc_mutators[i];
// TODO: ideally, want to use a lock-free data structure to prevent
// having to use a mutex here. see corresponding code in gc_mark_gray
      pthread_mutex_lock(&(m->lock));
      while (m->last_read < m->last_write) {
        clean = 0;
        (m->last_read)++;
        gc_mark_black((m->mark_buffer)[m->last_read]);
        gc_empty_collector_stack();
      }
      pthread_mutex_unlock(&(m->lock));
    }
  }
}

// TODO: seriously consider changing the mark() macro to color(),
// and sync up the header variable. that would make all of this code
// bit clearer...

void gc_mark_black(object obj) 
{
  // TODO: is sync required to get colors? probably not on the collector
  // thread (at least) since colors are only changed once during the clear
  // phase and before the first handshake.
  int markColor = ATOMIC_GET(&gc_color_mark);
  if (is_object_type(obj) && mark(obj) != markColor) {
    // Gray any child objects
    // Note we probably should use some form of atomics/synchronization
    // for cons and vector types, as these pointers could change.
    switch(type_of(obj)) {
      case cons_tag: {
        gc_collector_mark_gray(car(obj));
        gc_collector_mark_gray(cdr(obj));
        break;
      }
      case closure1_tag:
        gc_collector_mark_gray(((closure1) obj)->elt1);
        break;
      case closure2_tag:
        gc_collector_mark_gray(((closure2) obj)->elt1);
        gc_collector_mark_gray(((closure2) obj)->elt2);
      case closure3_tag:
        gc_collector_mark_gray(((closure3) obj)->elt1);
        gc_collector_mark_gray(((closure3) obj)->elt2);
        gc_collector_mark_gray(((closure3) obj)->elt3);
      case closure4_tag:
        gc_collector_mark_gray(((closure4) obj)->elt1);
        gc_collector_mark_gray(((closure4) obj)->elt2);
        gc_collector_mark_gray(((closure4) obj)->elt3);
        gc_collector_mark_gray(((closure4) obj)->elt4);
        break;
      case closureN_tag: {
        int i, n = ((closureN) obj)->num_elt;
        for (i = 0; i < n; i++) {
          gc_collector_mark_gray(((closureN) obj)->elts[i]);
        }
        break;
      }
      case vector_tag: {
        int i, n = ((vector) obj)->num_elt;
        for (i = 0; i < n; i++) {
          gc_collector_mark_gray(((vector) obj)->elts[i]);
        }
        break;
      }
      default:
      break;
    }
    mark(obj) = markColor;
  }
}

void gc_collector_mark_gray(object obj)
{
  // "Color" objects gray by adding them to the mark stack for further processing.
  //
  // Note that stack objects are always colored red during creation, so
  // they should never be added to the mark stack. Which would be bad because it
  // could lead to stack corruption.
  if (is_object_type(obj) && mark(obj) == gc_color_clear) {
    mark_stack = vpbuffer_add(mark_stack, &mark_stack_len, mark_stack_i++, obj);
  }
}

void gc_empty_collector_stack()
{
  // Mark stack is only used by the collector thread, so no sync needed
  while (mark_stack_i > 0) { // not empty
    mark_stack--;
    gc_mark_black(mark_stack[mark_stack_i]);
  }
}

void gc_handshake(gc_status_type s)
{
  gc_post_handshake(s);
  gc_wait_handshake();
}

void gc_post_handshake(gc_status_type s)
{
  int status = ATOMIC_GET(&gc_status_col);
  while (!ATOMIC_SET_IF_EQ(&gc_status_col, status, s)){}
}

void gc_wait_handshake()
{
  int i, statusm, statusc;
  struct timespec tim;
  tim.tv_sec = 0;
  tim.tv_nsec = 1;

  // TODO: same as in other places, need to either sync access to
  // mutator vars, or ensure only the collector uses them
  for (i = 0; i < Cyc_num_mutators; i++) {
    statusc = ATOMIC_GET(&gc_status_col);
    statusm = ATOMIC_GET(&(Cyc_mutators[i]->gc_status));
    if (statusc != statusm) {
      // At least for now, just give up quantum and come back to
      // this quickly to test again. This probably could be more
      // efficient.
      // TODO: also need to consider mutators that are blocked and
      // not cooperating.
      nanosleep(&tim, NULL);     
    }
  }
}

/////////////////////////////////////////////
// GC Collection cycle

// Main collector function
void gc_collector()
{
  int old_clear, old_mark;
  size_t freed = 0, max_freed = 0, total_size;
//#if GC_DEBUG_CONCISE_PRINTFS
  time_t sweep_start = time(NULL);
//#endif
  // TODO: what kind of sync is required here?

  //clear : 
  gc_stage = STAGE_CLEAR_OR_MARKING;
  // exchange values of markColor and clearColor
  old_clear = ATOMIC_GET(&gc_color_clear);
  old_mark = ATOMIC_GET(&gc_color_mark);
  while(!ATOMIC_SET_IF_EQ(&gc_color_clear, old_clear, old_mark)){}
  while(!ATOMIC_SET_IF_EQ(&gc_color_mark, old_mark, old_clear)){}
printf("DEBUG - swap clear %d / mark %d\n", gc_color_clear, gc_color_mark);
  gc_handshake(STATUS_SYNC1);
  //mark : 
  gc_handshake(STATUS_SYNC2);
  gc_stage = STAGE_TRACING;
  gc_post_handshake(STATUS_ASYNC);
  gc_mark_globals();
  gc_wait_handshake();
  //trace : 
  gc_collector_trace();
  gc_stage = STAGE_SWEEPING;
  //
  //sweep : 
  max_freed = gc_sweep(gc_get_heap(), &freed);
  // TODO: grow heap if it is mostly full after collection??
//#if GC_DEBUG_CONCISE_PRINTFS
    printf("sweep done, freed = %d, max_freed = %d, elapsed = %ld\n", 
      freed, max_freed, time(NULL) - sweep_start);
//#endif
  gc_stage = STAGE_RESTING;
}

void *collector_main(void *arg)
{
  while (1) {
    gc_collector();
    // TODO: how to schedule this thread?
    // this is inefficient but it should be good enough to 
    // at least stand up this collector. then we'll have to
    // come back and improve it
    sleep(1);
  }
}

static pthread_t collector_thread;

void gc_start_collector()
{
  if (pthread_create(&collector_thread, NULL, collector_main, &collector_thread)) {
    fprintf(stderr, "Error creating collector thread\n");
    exit(1);
  }
}

/////////////////////////////////////////////
// END tri-color marking section
/////////////////////////////////////////////


// Initialize runtime data structures for a thread.
// Must be called on the target thread itself during startup,
// to verify stack limits are setup correctly.
void gc_thread_data_init(gc_thread_data *thd, int mut_num, char *stack_base, long stack_size)
{
  char stack_ref;
  thd->stack_start = stack_base;
#if STACK_GROWS_DOWNWARD
  thd->stack_limit = stack_base - stack_size;
#else
  thd->stack_limit = stack_base + stack_size;
#endif
  if (check_overflow(stack_base, &stack_ref)){
    fprintf(stderr, 
      "Error: recompile with STACK_GROWS_DOWNWARD set to %d\n",
      (1 - STACK_GROWS_DOWNWARD));
    exit(1);
  }
  //thd->mutator_num = mut_num;
  thd->jmp_start = malloc(sizeof(jmp_buf));
  thd->gc_args = malloc(sizeof(object) * NUM_GC_ANS);
  thd->gc_num_args = 0;
  thd->moveBufLen = 0;
  gc_thr_grow_move_buffer(thd);
  thd->gc_alloc_color = ATOMIC_GET(&gc_color_clear);
  thd->gc_status = ATOMIC_GET(&gc_status_col);
  thd->last_write = 0;
  thd->last_read = 0;
  thd->mark_buffer_len = 128;
  thd->mark_buffer = vpbuffer_realloc(thd->mark_buffer, &(thd->mark_buffer_len));
  if (pthread_mutex_init(&(thd->lock), NULL) != 0) {
    fprintf(stderr, "Unable to initialize thread mutex\n");
    exit(1);
  }
}

void gc_thread_data_free(gc_thread_data *thd)
{
  if (thd) {
    if (thd->jmp_start) free(thd->jmp_start);
    if (thd->gc_args) free(thd->gc_args);
    if (thd->moveBuf) free(thd->moveBuf);
    if (thd->mark_buffer) free(thd->mark_buffer);
    free(thd);
  }
}

//// Unit testing:
//int main(int argc, char **argv) {
//  int a = 1, b = 2, c = 3, i;
//  void **buf = NULL;
//  int size = 1;
//
//  buf = vpbuffer_realloc(buf, &size);
//  printf("buf = %p, size = %d\n", buf, size);
//  buf = vpbuffer_add(buf, &size, 0, &a);
//  printf("buf = %p, size = %d\n", buf, size);
//  buf = vpbuffer_add(buf, &size, 1, &b);
//  printf("buf = %p, size = %d\n", buf, size);
//  buf = vpbuffer_add(buf, &size, 2, &c);
//  printf("buf = %p, size = %d\n", buf, size);
//  buf = vpbuffer_add(buf, &size, 3, &a);
//  printf("buf = %p, size = %d\n", buf, size);
//  buf = vpbuffer_add(buf, &size, 4, &b);
//  printf("buf = %p, size = %d\n", buf, size);
//  for (i = 5; i < 20; i++) {
//    buf = vpbuffer_add(buf, &size, i, &c);
//  }
//
//  for (i = 0; i < 20; i++){
//    printf("%d\n", *((int *) buf[i]));
//  }
//  vpbuffer_free(buf);
//  printf("buf = %p, size = %d\n", buf, size);
//  return 0;
//}
//