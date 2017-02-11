/**
 ** This file was automatically generated by the Cyclone scheme compiler
 ** http://justinethier.github.io/cyclone/
 **
 ** (c) 2014-2017 Justin Ethier
 ** Version 0.3.4.1 (beta)
 **
 **/

#define closcall1(td, clo,a1) \
if (type_is_pair_prim(clo)) { \
   Cyc_apply(td, 0, (closure)(a1), clo); \
} else { \
   ((clo)->fn)(td, 1, clo,a1);\
}
#define return_closcall1(td, clo,a1) { \
 char top; \
 if (stack_overflow(&top, (((gc_thread_data *)data)->stack_limit))) { \
     object buf[1]; buf[0] = a1;\
     GC(td, clo, buf, 1); \
     return; \
 } else {\
     closcall1(td, (closure) (clo),a1); \
     return;\
 } \
}

#define return_direct1(td, _fn,a1) { \
 char top; \
 if (stack_overflow(&top, (((gc_thread_data *)data)->stack_limit))) { \
     object buf[1]; buf[0] = a1; \
     mclosure0(c1, (function_type) _fn); \
     GC(td, &c1, buf, 1); \
     return; \
 } else { \
     (_fn)(td, 1, (closure)_fn,a1); \
 }}

#define closcall2(td, clo,a1,a2) \
if (type_is_pair_prim(clo)) { \
   Cyc_apply(td, 1, (closure)(a1), clo,a2); \
} else { \
   ((clo)->fn)(td, 2, clo,a1,a2);\
}
#define return_closcall2(td, clo,a1,a2) { \
 char top; \
 if (stack_overflow(&top, (((gc_thread_data *)data)->stack_limit))) { \
     object buf[2]; buf[0] = a1;buf[1] = a2;\
     GC(td, clo, buf, 2); \
     return; \
 } else {\
     closcall2(td, (closure) (clo),a1,a2); \
     return;\
 } \
}

#define return_direct2(td, _fn,a1,a2) { \
 char top; \
 if (stack_overflow(&top, (((gc_thread_data *)data)->stack_limit))) { \
     object buf[2]; buf[0] = a1;buf[1] = a2; \
     mclosure0(c1, (function_type) _fn); \
     GC(td, &c1, buf, 2); \
     return; \
 } else { \
     (_fn)(td, 2, (closure)_fn,a1,a2); \
 }}

#include "cyclone/types.h"
object __glo_lib_91init_117schemelazy_scheme_lazy = NULL;
object __glo_promise_127_scheme_lazy = NULL;
object __glo_make_91promise_scheme_lazy = NULL;
object __glo_delay_91force_scheme_lazy = NULL;
object __glo_delay_scheme_lazy = NULL;
object __glo_force_scheme_lazy = NULL;
extern object __glo_member_scheme_base;
extern object __glo_assoc_scheme_base;
extern object __glo_cons_91source_scheme_base;
extern object __glo_syntax_91rules_scheme_base;
extern object __glo_letrec_85_scheme_base;
extern object __glo_guard_scheme_base;
extern object __glo_guard_91aux_scheme_base;
extern object __glo_define_91record_91type_scheme_base;
extern object __glo_record_127_scheme_base;
extern object __glo_register_91simple_91type_scheme_base;
extern object __glo_make_91type_91predicate_scheme_base;
extern object __glo_make_91constructor_scheme_base;
extern object __glo_make_91getter_scheme_base;
extern object __glo_make_91setter_scheme_base;
extern object __glo_slot_91set_67_scheme_base;
extern object __glo_type_91slot_91offset_scheme_base;
extern object __glo_receive_scheme_base;
extern object __glo_abs_scheme_base;
extern object __glo_max_scheme_base;
extern object __glo_min_scheme_base;
extern object __glo_modulo_scheme_base;
extern object __glo_floor_91remainder_scheme_base;
extern object __glo_even_127_scheme_base;
extern object __glo_exact_91integer_127_scheme_base;
extern object __glo_exact_91integer_91sqrt_scheme_base;
extern object __glo_exact_127_scheme_base;
extern object __glo_inexact_127_scheme_base;
extern object __glo_odd_127_scheme_base;
extern object __glo_complex_127_scheme_base;
extern object __glo_rational_127_scheme_base;
extern object __glo_gcd_scheme_base;
extern object __glo_lcm_scheme_base;
extern object __glo_quotient_scheme_base;
extern object __glo_remainder_scheme_base;
extern object __glo_truncate_91quotient_scheme_base;
extern object __glo_truncate_91remainder_scheme_base;
extern object __glo_truncate_95_scheme_base;
extern object __glo_floor_91quotient_scheme_base;
extern object __glo_floor_91remainder_scheme_base;
extern object __glo_floor_95_scheme_base;
extern object __glo_square_scheme_base;
extern object __glo_expt_scheme_base;
extern object __glo_call_91with_91current_91continuation_scheme_base;
extern object __glo_call_95cc_scheme_base;
extern object __glo_call_91with_91values_scheme_base;
extern object __glo_dynamic_91wind_scheme_base;
extern object __glo_values_scheme_base;
extern object __glo_char_123_127_scheme_base;
extern object __glo_char_121_127_scheme_base;
extern object __glo_char_125_127_scheme_base;
extern object __glo_char_121_123_127_scheme_base;
extern object __glo_char_125_123_127_scheme_base;
extern object __glo_string_123_127_scheme_base;
extern object __glo_string_121_127_scheme_base;
extern object __glo_string_121_123_127_scheme_base;
extern object __glo_string_125_127_scheme_base;
extern object __glo_string_125_123_127_scheme_base;
extern object __glo_foldl_scheme_base;
extern object __glo_foldr_scheme_base;
extern object __glo_not_scheme_base;
extern object __glo_list_127_scheme_base;
extern object __glo_zero_127_scheme_base;
extern object __glo_positive_127_scheme_base;
extern object __glo_negative_127_scheme_base;
extern object __glo_append_scheme_base;
extern object __glo__list_scheme_base;
extern object __glo_make_91list_scheme_base;
extern object __glo_list_91copy_scheme_base;
extern object __glo_map_scheme_base;
extern object __glo_for_91each_scheme_base;
extern object __glo_list_91tail_scheme_base;
extern object __glo_list_91ref_scheme_base;
extern object __glo_list_91set_67_scheme_base;
extern object __glo_reverse_scheme_base;
extern object __glo_boolean_123_127_scheme_base;
extern object __glo_symbol_123_127_scheme_base;
extern object __glo_Cyc_91obj_123_127_scheme_base;
extern object __glo_vector_scheme_base;
extern object __glo_vector_91append_scheme_base;
extern object __glo_vector_91copy_scheme_base;
extern object __glo_vector_91copy_67_scheme_base;
extern object __glo_vector_91fill_67_scheme_base;
extern object __glo_vector_91_125list_scheme_base;
extern object __glo_vector_91_125string_scheme_base;
extern object __glo_vector_91map_scheme_base;
extern object __glo_vector_91for_91each_scheme_base;
extern object __glo_make_91string_scheme_base;
extern object __glo_string_scheme_base;
extern object __glo_string_91copy_scheme_base;
extern object __glo_string_91copy_67_scheme_base;
extern object __glo_string_91fill_67_scheme_base;
extern object __glo_string_91_125list_scheme_base;
extern object __glo_string_91_125vector_scheme_base;
extern object __glo_string_91map_scheme_base;
extern object __glo_string_91for_91each_scheme_base;
extern object __glo_make_91parameter_scheme_base;
extern object __glo_current_91output_91port_scheme_base;
extern object __glo_current_91input_91port_scheme_base;
extern object __glo_current_91error_91port_scheme_base;
extern object __glo_call_91with_91port_scheme_base;
extern object __glo_error_scheme_base;
extern object __glo_raise_scheme_base;
extern object __glo_raise_91continuable_scheme_base;
extern object __glo_with_91handler_scheme_base;
extern object __glo_with_91exception_91handler_scheme_base;
extern object __glo_Cyc_91add_91exception_91handler_scheme_base;
extern object __glo_Cyc_91remove_91exception_91handler_scheme_base;
extern object __glo_newline_scheme_base;
extern object __glo_write_91char_scheme_base;
extern object __glo_write_91string_scheme_base;
extern object __glo_flush_91output_91port_scheme_base;
extern object __glo_read_91line_scheme_base;
extern object __glo_read_91string_scheme_base;
extern object __glo_input_91port_127_scheme_base;
extern object __glo_output_91port_127_scheme_base;
extern object __glo_input_91port_91open_127_scheme_base;
extern object __glo_output_91port_91open_127_scheme_base;
extern object __glo_get_91output_91string_scheme_base;
extern object __glo_open_91output_91string_scheme_base;
extern object __glo_open_91input_91string_scheme_base;
extern object __glo_get_91output_91bytevector_scheme_base;
extern object __glo_open_91input_91bytevector_scheme_base;
extern object __glo_open_91output_91bytevector_scheme_base;
extern object __glo_features_scheme_base;
extern object __glo_Cyc_91version_scheme_base;
extern object __glo_any_scheme_base;
extern object __glo_every_scheme_base;
extern object __glo_and_scheme_base;
extern object __glo_or_scheme_base;
extern object __glo_let_scheme_base;
extern object __glo_let_85_scheme_base;
extern object __glo_letrec_scheme_base;
extern object __glo_let_85_91values_scheme_base;
extern object __glo_let_91values_scheme_base;
extern object __glo_begin_scheme_base;
extern object __glo__case_scheme_base;
extern object __glo_cond_scheme_base;
extern object __glo_cond_91expand_scheme_base;
extern object __glo__do_scheme_base;
extern object __glo_when_scheme_base;
extern object __glo_unless_scheme_base;
extern object __glo_quasiquote_scheme_base;
extern object __glo_floor_scheme_base;
extern object __glo_ceiling_scheme_base;
extern object __glo_truncate_scheme_base;
extern object __glo_round_scheme_base;
extern object __glo_exact_scheme_base;
extern object __glo_inexact_scheme_base;
extern object __glo_eof_91object_scheme_base;
extern object __glo_syntax_91error_scheme_base;
extern object __glo_bytevector_91copy_scheme_base;
extern object __glo_bytevector_91copy_67_scheme_base;
extern object __glo_utf8_91_125string_scheme_base;
extern object __glo_string_91_125utf8_scheme_base;
extern object __glo_denominator_scheme_base;
extern object __glo_numerator_scheme_base;
extern object __glo_parameterize_scheme_base;
#include "cyclone/runtime.h"
defsymbol(lambda);
defsymbol(make_91promise);
static void __lambda_11(void *data, int argc, closure _,object k_7320) ;
static void __lambda_10(void *data, int argc, closure _,object k_7326, object proc_737) ;
static void __lambda_9(void *data, int argc, object self_7360, object result_91ready_127_739, object result_738) ;
static void __lambda_8(void *data, int argc, object self_7361, object result_91ready_127_739) ;
static void __lambda_7(void *data, int argc, object self_7362, object result_738) ;
static void __lambda_6(void *data, int argc, object self_7363, object k_7327) ;
static void __lambda_5(void *data, int argc, object self_7364, object x_7310) ;
static void __lambda_4(void *data, int argc, object self_7365, object r_7329) ;
static void __lambda_3(void *data, int argc, object self_7366, object r_7330) ;
static void __lambda_2(void *data, int argc, closure _,object k_7333, object expr_7313, object rename_7312, object compare_7311) ;
static void __lambda_1(void *data, int argc, closure _,object k_7346, object expr_7316, object rename_7315, object compare_7314) ;
static void __lambda_0(void *data, int argc, closure _,object k_7359, object object_7317) ;

static void __lambda_11(void *data, int argc, closure _,object k_7320) {
  Cyc_st_add(data, "scheme/lazy.sld:lib-init:schemelazy");
return_closcall1(data,  k_7320,  global_set(__glo_promise_127_scheme_lazy, primitive_procedure_127));; 
}

static void __lambda_10(void *data, int argc, closure _,object k_7326, object proc_737) {
  Cyc_st_add(data, "scheme/lazy.sld:make-promise");

closureN_type c_73109;
c_73109.hdr.mark = gc_color_red;
 c_73109.hdr.grayed = 0;
c_73109.tag = closureN_tag;
 c_73109.fn = (function_type)__lambda_9;
c_73109.num_args = 2;
c_73109.num_elements = 2;
c_73109.elements = (object *)alloca(sizeof(object) * 2);
c_73109.elements[0] = k_7326;
c_73109.elements[1] = proc_737;

return_closcall2(data,(closure)&c_73109,  boolean_f, boolean_f);; 
}

static void __lambda_9(void *data, int argc, object self_7360, object result_91ready_127_739, object result_738) {
  
closureN_type c_73111;
c_73111.hdr.mark = gc_color_red;
 c_73111.hdr.grayed = 0;
c_73111.tag = closureN_tag;
 c_73111.fn = (function_type)__lambda_8;
c_73111.num_args = 1;
c_73111.num_elements = 3;
c_73111.elements = (object *)alloca(sizeof(object) * 3);
c_73111.elements[0] = ((closureN)self_7360)->elements[0];
c_73111.elements[1] = ((closureN)self_7360)->elements[1];
c_73111.elements[2] = result_738;


make_cell(c_73156,result_91ready_127_739);
return_closcall1(data,(closure)&c_73111,  &c_73156);; 
}

static void __lambda_8(void *data, int argc, object self_7361, object result_91ready_127_739) {
  
closureN_type c_73113;
c_73113.hdr.mark = gc_color_red;
 c_73113.hdr.grayed = 0;
c_73113.tag = closureN_tag;
 c_73113.fn = (function_type)__lambda_7;
c_73113.num_args = 1;
c_73113.num_elements = 3;
c_73113.elements = (object *)alloca(sizeof(object) * 3);
c_73113.elements[0] = ((closureN)self_7361)->elements[0];
c_73113.elements[1] = ((closureN)self_7361)->elements[1];
c_73113.elements[2] = result_91ready_127_739;


make_cell(c_73152,((closureN)self_7361)->elements[2]);
return_closcall1(data,(closure)&c_73113,  &c_73152);; 
}

static void __lambda_7(void *data, int argc, object self_7362, object result_738) {
  
closureN_type c_73116;
c_73116.hdr.mark = gc_color_red;
 c_73116.hdr.grayed = 0;
c_73116.tag = closureN_tag;
 c_73116.fn = (function_type)__lambda_6;
c_73116.num_args = 0;
c_73116.num_elements = 3;
c_73116.elements = (object *)alloca(sizeof(object) * 3);
c_73116.elements[0] = ((closureN)self_7362)->elements[1];
c_73116.elements[1] = result_738;
c_73116.elements[2] = ((closureN)self_7362)->elements[2];

return_closcall1(data,  ((closureN)self_7362)->elements[0],  &c_73116);; 
}

static void __lambda_6(void *data, int argc, object self_7363, object k_7327) {
  if( (boolean_f != cell_get(((closureN)self_7363)->elements[2])) ){ 
  return_closcall1(data,  k_7327,  cell_get(((closureN)self_7363)->elements[1]));
} else { 
  
closureN_type c_73126;
c_73126.hdr.mark = gc_color_red;
 c_73126.hdr.grayed = 0;
c_73126.tag = closureN_tag;
 c_73126.fn = (function_type)__lambda_5;
c_73126.num_args = 1;
c_73126.num_elements = 3;
c_73126.elements = (object *)alloca(sizeof(object) * 3);
c_73126.elements[0] = k_7327;
c_73126.elements[1] = ((closureN)self_7363)->elements[1];
c_73126.elements[2] = ((closureN)self_7363)->elements[2];

return_closcall1(data,  ((closureN)self_7363)->elements[0],  &c_73126);}
; 
}

static void __lambda_5(void *data, int argc, object self_7364, object x_7310) {
  if( (boolean_f != cell_get(((closureN)self_7364)->elements[2])) ){ 
  return_closcall1(data,  ((closureN)self_7364)->elements[0],  cell_get(((closureN)self_7364)->elements[1]));
} else { 
  
closureN_type c_73136;
c_73136.hdr.mark = gc_color_red;
 c_73136.hdr.grayed = 0;
c_73136.tag = closureN_tag;
 c_73136.fn = (function_type)__lambda_4;
c_73136.num_args = 1;
c_73136.num_elements = 3;
c_73136.elements = (object *)alloca(sizeof(object) * 3);
c_73136.elements[0] = ((closureN)self_7364)->elements[0];
c_73136.elements[1] = ((closureN)self_7364)->elements[1];
c_73136.elements[2] = ((closureN)self_7364)->elements[2];

return_closcall1(data,(closure)&c_73136,  Cyc_set_cell(data, ((closureN)self_7364)->elements[1], x_7310));}
; 
}

static void __lambda_4(void *data, int argc, object self_7365, object r_7329) {
  
closureN_type c_73138;
c_73138.hdr.mark = gc_color_red;
 c_73138.hdr.grayed = 0;
c_73138.tag = closureN_tag;
 c_73138.fn = (function_type)__lambda_3;
c_73138.num_args = 1;
c_73138.num_elements = 2;
c_73138.elements = (object *)alloca(sizeof(object) * 2);
c_73138.elements[0] = ((closureN)self_7365)->elements[0];
c_73138.elements[1] = ((closureN)self_7365)->elements[1];

return_closcall1(data,(closure)&c_73138,  Cyc_set_cell(data, ((closureN)self_7365)->elements[2], boolean_t));; 
}

static void __lambda_3(void *data, int argc, object self_7366, object r_7330) {
  return_closcall1(data,  ((closureN)self_7366)->elements[0],  cell_get(((closureN)self_7366)->elements[1]));; 
}

static void __lambda_2(void *data, int argc, closure _,object k_7333, object expr_7313, object rename_7312, object compare_7311) {
  Cyc_st_add(data, "scheme/lazy.sld:delay-force");

make_pair(c_73104,Cyc_cadr(data, expr_7313), NULL);

make_pair(c_73101,NULL, &c_73104);

make_pair(c_7398,quote_lambda, &c_73101);

make_pair(c_7395,&c_7398, NULL);

make_pair(c_7392,quote_make_91promise, &c_7395);
return_closcall1(data,  k_7333,  &c_7392);; 
}

static void __lambda_1(void *data, int argc, closure _,object k_7346, object expr_7316, object rename_7315, object compare_7314) {
  Cyc_st_add(data, "scheme/lazy.sld:delay");

make_pair(c_7385,Cyc_cadr(data, expr_7316), NULL);

make_pair(c_7382,NULL, &c_7385);

make_pair(c_7379,quote_lambda, &c_7382);

make_pair(c_7376,&c_7379, NULL);

make_pair(c_7373,quote_make_91promise, &c_7376);
return_closcall1(data,  k_7346,  &c_7373);; 
}

static void __lambda_0(void *data, int argc, closure _,object k_7359, object object_7317) {
  Cyc_st_add(data, "scheme/lazy.sld:force");
return_closcall1(data,  object_7317,  k_7359);; 
}

void c_schemelazy_entry_pt(data, argc, cont,value) void *data; int argc; closure cont; object value;{ 
  quote_lambda = find_or_add_symbol("lambda");
  quote_make_91promise = find_or_add_symbol("make-promise");

  add_global((object *) &__glo_lib_91init_117schemelazy_scheme_lazy);
  add_global((object *) &__glo_promise_127_scheme_lazy);
  add_global((object *) &__glo_make_91promise_scheme_lazy);
  add_global((object *) &__glo_delay_91force_scheme_lazy);
  add_global((object *) &__glo_delay_scheme_lazy);
  add_global((object *) &__glo_force_scheme_lazy);
  add_symbol(quote_lambda);
  add_symbol(quote_make_91promise);
  mclosure0(c_73157, (function_type)__lambda_11);c_73157.num_args = 0; 
  __glo_lib_91init_117schemelazy_scheme_lazy = &c_73157; 
  mclosure0(c_73107, (function_type)__lambda_10);c_73107.num_args = 1; 
  __glo_make_91promise_scheme_lazy = &c_73107; 
  mmacro(c_7388, (function_type)__lambda_2);c_7388.num_args = 3; 
  __glo_delay_91force_scheme_lazy = &c_7388; 
  mmacro(c_7369, (function_type)__lambda_1);c_7369.num_args = 3; 
  __glo_delay_scheme_lazy = &c_7369; 
  mclosure0(c_7367, (function_type)__lambda_0);c_7367.num_args = 1; 
  __glo_force_scheme_lazy = &c_7367; 
  __glo_promise_127_scheme_lazy = boolean_f; 

  make_cvar(cvar_73161, (object *)&__glo_lib_91init_117schemelazy_scheme_lazy);make_pair(pair_73162, find_or_add_symbol("lib-init:schemelazy"), &cvar_73161);
  make_cvar(cvar_73163, (object *)&__glo_promise_127_scheme_lazy);make_pair(pair_73164, find_or_add_symbol("promise?"), &cvar_73163);
  make_cvar(cvar_73165, (object *)&__glo_make_91promise_scheme_lazy);make_pair(pair_73166, find_or_add_symbol("make-promise"), &cvar_73165);
  make_cvar(cvar_73167, (object *)&__glo_delay_91force_scheme_lazy);make_pair(pair_73168, find_or_add_symbol("delay-force"), &cvar_73167);
  make_cvar(cvar_73169, (object *)&__glo_delay_scheme_lazy);make_pair(pair_73170, find_or_add_symbol("delay"), &cvar_73169);
  make_cvar(cvar_73171, (object *)&__glo_force_scheme_lazy);make_pair(pair_73172, find_or_add_symbol("force"), &cvar_73171);
make_pair(c_73173, &pair_73162,Cyc_global_variables);
make_pair(c_73174, &pair_73164, &c_73173);
make_pair(c_73175, &pair_73166, &c_73174);
make_pair(c_73176, &pair_73168, &c_73175);
make_pair(c_73177, &pair_73170, &c_73176);
make_pair(c_73178, &pair_73172, &c_73177);
Cyc_global_variables = &c_73178;
cont = ((closure1_type *)cont)->element;
(((closure)__glo_lib_91init_117schemelazy_scheme_lazy)->fn)(data, 1, cont, cont);
}
