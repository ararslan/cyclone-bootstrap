/**
 ** This file was automatically generated by the Cyclone scheme compiler
 **
 ** (c) 2014-2016 Justin Ethier
 ** Version 0.0.4 (Pre-release)
 **
 **/

#define closcall1(td,cfn,a1) if (type_of(cfn) == cons_tag || prim(cfn)) { Cyc_apply(td,0, (closure)a1, cfn); } else { ((cfn)->fn)(td,1,cfn,a1);}
/* Check for GC, then call given continuation closure */
#define return_closcall1(td,cfn,a1) \
{char stack; \
 if (check_overflow(&stack,(((gc_thread_data *)data)->stack_limit))) { \
     object buf[1]; buf[0] = a1;\
     GC(td,cfn,buf,1); return; \
 } else {closcall1(td,(closure) (cfn),a1); return;}}

/* Check for GC, then call C function directly */
#define return_direct1(td,_fn,a1) { \
 char stack; \
 if (check_overflow(&stack,(((gc_thread_data *)data)->stack_limit))) { \
     object buf[1]; buf[0] = a1; \
     mclosure0(c1, _fn); \
     GC(td,&c1, buf, 1); return; \
 } else { (_fn)(td,1,(closure)_fn,a1); }}

#define closcall2(td,cfn,a1,a2) if (type_of(cfn) == cons_tag || prim(cfn)) { Cyc_apply(td,1, (closure)a1, cfn,a2); } else { ((cfn)->fn)(td,2,cfn,a1,a2);}
/* Check for GC, then call given continuation closure */
#define return_closcall2(td,cfn,a1,a2) \
{char stack; \
 if (check_overflow(&stack,(((gc_thread_data *)data)->stack_limit))) { \
     object buf[2]; buf[0] = a1;buf[1] = a2;\
     GC(td,cfn,buf,2); return; \
 } else {closcall2(td,(closure) (cfn),a1,a2); return;}}

/* Check for GC, then call C function directly */
#define return_direct2(td,_fn,a1,a2) { \
 char stack; \
 if (check_overflow(&stack,(((gc_thread_data *)data)->stack_limit))) { \
     object buf[2]; buf[0] = a1;buf[1] = a2; \
     mclosure0(c1, _fn); \
     GC(td,&c1, buf, 2); return; \
 } else { (_fn)(td,2,(closure)_fn,a1,a2); }}

#include "cyclone/types.h"
object __glo_lib_91init_117schemeprocess_19191context = nil;
object __glo_get_91environment_91variable = nil;
object __glo_command_91line = nil;
object __glo_emergency_91exit = nil;
#include "cyclone/runtime.h"
static void __lambda_3(void *data, int argc, closure _,object k_733) ;
static void __lambda_2(void *data, int argc, object self_737, object r_734) ;
static void __lambda_1(void *data, int argc, closure _, object k, object env_var) ;
static void __lambda_0(void *data, int argc, closure _, object k) ;

static void __lambda_3(void *data, int argc, closure _,object k_733) {
  Cyc_st_add(data, "scheme/process-context.sld:lib-init:schemeprocess_91context");

closureN_type c_7312;
c_7312.hdr.mark = gc_color_red;
 c_7312.hdr.grayed = 0;
c_7312.tag = closureN_tag;
 c_7312.fn = (function_type)__lambda_2;
c_7312.num_args = 1;
c_7312.num_elt = 1;
c_7312.elts = (object *)alloca(sizeof(object) * 1);
c_7312.elts[0] = k_733;


make_int(c_7317, 0);
return_closcall1(data,(closure)&c_7312,  &c_7317);; 
}

static void __lambda_2(void *data, int argc, object self_737, object r_734) {
  Cyc_st_add(data, "scheme/process-context.sld:lib-init:schemeprocess_91context");
return_closcall1(data,  ((closureN)self_737)->elts[0],  global_set(__glo_emergency_91exit, primitive_exit));; 
}

static void __lambda_1(void *data, int argc, closure _, object k, object env_var) { 
        const char *v = NULL;
        Cyc_check_str(data, env_var);
        v = getenv(string_str(env_var));
        if (v == NULL) {
          return_closcall1(data, k, boolean_f);
        } else {
          make_string(str, v);
          return_closcall1(data, k, &str);
        }
       }
static void __lambda_0(void *data, int argc, closure _, object k) { int i;
        object lis = nil;
        for (i = _cyc_argc; i > 0; i--) {
          object ps = alloca(sizeof(string_type));
          object pl = alloca(sizeof(cons_type));
          make_string(s, _cyc_argv[i - 1]);
          memcpy(ps, &s, sizeof(string_type));
          ((list)pl)->hdr.mark = gc_color_red;
          ((list)pl)->hdr.grayed = 0;
          ((list)pl)->tag = cons_tag;
          ((list)pl)->cons_car = ps;
          ((list)pl)->cons_cdr = lis;
          lis = pl;
        }
        return_closcall1(data, k, lis);  }
void c_schemeprocess_91context_entry_pt(data, argc, cont,value) void *data; int argc; closure cont; object value;{ 

  add_global((object *) &__glo_lib_91init_117schemeprocess_19191context);
  add_global((object *) &__glo_get_91environment_91variable);
  add_global((object *) &__glo_command_91line);
  add_global((object *) &__glo_emergency_91exit);
  mclosure0(c_7310, (function_type)__lambda_3);c_7310.num_args = 0; 
  __glo_lib_91init_117schemeprocess_19191context = &c_7310; 
  mclosure0(c_739, (function_type)__lambda_1);c_739.num_args = 1; 
  __glo_get_91environment_91variable = &c_739; 
  mclosure0(c_738, (function_type)__lambda_0);c_738.num_args = 0; 
  __glo_command_91line = &c_738; 
  __glo_emergency_91exit = boolean_f; 

  make_cvar(cvar_7318, (object *)&__glo_lib_91init_117schemeprocess_19191context);make_cons(pair_7319, find_or_add_symbol("lib-init:schemeprocess_91context"), &cvar_7318);
  make_cvar(cvar_7320, (object *)&__glo_get_91environment_91variable);make_cons(pair_7321, find_or_add_symbol("get-environment-variable"), &cvar_7320);
  make_cvar(cvar_7322, (object *)&__glo_command_91line);make_cons(pair_7323, find_or_add_symbol("command-line"), &cvar_7322);
  make_cvar(cvar_7324, (object *)&__glo_emergency_91exit);make_cons(pair_7325, find_or_add_symbol("emergency-exit"), &cvar_7324);
make_cons(c_7326, &pair_7319,Cyc_global_variables);
make_cons(c_7327, &pair_7321, &c_7326);
make_cons(c_7328, &pair_7323, &c_7327);
make_cons(c_7329, &pair_7325, &c_7328);
Cyc_global_variables = &c_7329;
cont = ((closure1_type *)cont)->elt1;
(((closure)__glo_lib_91init_117schemeprocess_19191context)->fn)(data, 1, cont, cont);
}