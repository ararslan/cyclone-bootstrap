/**
 ** This file was automatically generated by the Cyclone scheme compiler
 **
 ** (c) 2014 Justin Ethier
 ** Version 0.0.2 (Pre-release)
 **
 **/

#define closcall0(cfn) ((cfn)->fn)(0,cfn)
/* Check for GC, then call given continuation closure */
#define return_closcall0(cfn) \
{char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[0]; \
     GC(cfn,buf,0); return; \
 } else {closcall0((closure) (cfn)); return;}}

/* Check for GC, then call C function directly */
#define return_direct0(_fn) { \
 char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[0];  \
     mclosure0(c1, _fn); \
     GC(&c1, buf, 0); return; \
 } else { (_fn)(0,(closure)_fn); }}

#define closcall1(cfn,a1) if (type_of(cfn) == cons_tag || prim(cfn)) { Cyc_apply(0, (closure)a1, cfn); } else { ((cfn)->fn)(1,cfn,a1);}
/* Check for GC, then call given continuation closure */
#define return_closcall1(cfn,a1) \
{char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[1]; buf[0] = a1;\
     GC(cfn,buf,1); return; \
 } else {closcall1((closure) (cfn),a1); return;}}

/* Check for GC, then call C function directly */
#define return_direct1(_fn,a1) { \
 char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[1]; buf[0] = a1; \
     mclosure0(c1, _fn); \
     GC(&c1, buf, 1); return; \
 } else { (_fn)(1,(closure)_fn,a1); }}

#define closcall2(cfn,a1,a2) if (type_of(cfn) == cons_tag || prim(cfn)) { Cyc_apply(1, (closure)a1, cfn,a2); } else { ((cfn)->fn)(2,cfn,a1,a2);}
/* Check for GC, then call given continuation closure */
#define return_closcall2(cfn,a1,a2) \
{char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[2]; buf[0] = a1;buf[1] = a2;\
     GC(cfn,buf,2); return; \
 } else {closcall2((closure) (cfn),a1,a2); return;}}

/* Check for GC, then call C function directly */
#define return_direct2(_fn,a1,a2) { \
 char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[2]; buf[0] = a1;buf[1] = a2; \
     mclosure0(c1, _fn); \
     GC(&c1, buf, 2); return; \
 } else { (_fn)(2,(closure)_fn,a1,a2); }}

#define closcall3(cfn,a1,a2,a3) if (type_of(cfn) == cons_tag || prim(cfn)) { Cyc_apply(2, (closure)a1, cfn,a2,a3); } else { ((cfn)->fn)(3,cfn,a1,a2,a3);}
/* Check for GC, then call given continuation closure */
#define return_closcall3(cfn,a1,a2,a3) \
{char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[3]; buf[0] = a1;buf[1] = a2;buf[2] = a3;\
     GC(cfn,buf,3); return; \
 } else {closcall3((closure) (cfn),a1,a2,a3); return;}}

/* Check for GC, then call C function directly */
#define return_direct3(_fn,a1,a2,a3) { \
 char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[3]; buf[0] = a1;buf[1] = a2;buf[2] = a3; \
     mclosure0(c1, _fn); \
     GC(&c1, buf, 3); return; \
 } else { (_fn)(3,(closure)_fn,a1,a2,a3); }}

#define closcall4(cfn,a1,a2,a3,a4) if (type_of(cfn) == cons_tag || prim(cfn)) { Cyc_apply(3, (closure)a1, cfn,a2,a3,a4); } else { ((cfn)->fn)(4,cfn,a1,a2,a3,a4);}
/* Check for GC, then call given continuation closure */
#define return_closcall4(cfn,a1,a2,a3,a4) \
{char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[4]; buf[0] = a1;buf[1] = a2;buf[2] = a3;buf[3] = a4;\
     GC(cfn,buf,4); return; \
 } else {closcall4((closure) (cfn),a1,a2,a3,a4); return;}}

/* Check for GC, then call C function directly */
#define return_direct4(_fn,a1,a2,a3,a4) { \
 char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[4]; buf[0] = a1;buf[1] = a2;buf[2] = a3;buf[3] = a4; \
     mclosure0(c1, _fn); \
     GC(&c1, buf, 4); return; \
 } else { (_fn)(4,(closure)_fn,a1,a2,a3,a4); }}

#define closcall5(cfn,a1,a2,a3,a4,a5) if (type_of(cfn) == cons_tag || prim(cfn)) { Cyc_apply(4, (closure)a1, cfn,a2,a3,a4,a5); } else { ((cfn)->fn)(5,cfn,a1,a2,a3,a4,a5);}
/* Check for GC, then call given continuation closure */
#define return_closcall5(cfn,a1,a2,a3,a4,a5) \
{char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[5]; buf[0] = a1;buf[1] = a2;buf[2] = a3;buf[3] = a4;buf[4] = a5;\
     GC(cfn,buf,5); return; \
 } else {closcall5((closure) (cfn),a1,a2,a3,a4,a5); return;}}

/* Check for GC, then call C function directly */
#define return_direct5(_fn,a1,a2,a3,a4,a5) { \
 char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[5]; buf[0] = a1;buf[1] = a2;buf[2] = a3;buf[3] = a4;buf[4] = a5; \
     mclosure0(c1, _fn); \
     GC(&c1, buf, 5); return; \
 } else { (_fn)(5,(closure)_fn,a1,a2,a3,a4,a5); }}

#include "cyclone/types.h"
object __glo_lib_91init_117schemecyclonemacros = nil;
object __glo_macro_117expand = nil;
object __glo_macro_117macro_127 = nil;
object __glo_define_91syntax_127 = nil;
object __glo_macro_117get_91defined_91macros = nil;
object __glo_macro_117add_67 = nil;
object __glo__85macro_117defined_91macros_85 = nil;
extern object __glo_call_91with_91current_91continuation;
extern object __glo_call_95cc;
extern object __glo_call_91with_91values;
extern object __glo_dynamic_91wind;
extern object __glo_values;
extern object __glo_char_123_127;
extern object __glo_char_121_127;
extern object __glo_char_125_127;
extern object __glo_char_121_123_127;
extern object __glo_char_125_123_127;
extern object __glo_string_123_127;
extern object __glo_string_121_127;
extern object __glo_string_121_123_127;
extern object __glo_string_125_127;
extern object __glo_string_125_123_127;
extern object __glo_foldl;
extern object __glo_foldr;
extern object __glo_not;
extern object __glo_list_127;
extern object __glo_zero_127;
extern object __glo_positive_127;
extern object __glo_negative_127;
extern object __glo_append;
extern object __glo__list;
extern object __glo_make_91list;
extern object __glo_list_91copy;
extern object __glo_map;
extern object __glo_for_91each;
extern object __glo_list_91tail;
extern object __glo_list_91ref;
extern object __glo_list_91set_67;
extern object __glo_reverse;
extern object __glo_boolean_123_127;
extern object __glo_symbol_123_127;
extern object __glo_Cyc_91obj_123_127;
extern object __glo_vector;
extern object __glo_vector_91append;
extern object __glo_vector_91copy;
extern object __glo_vector_91copy_67;
extern object __glo_vector_91fill_67;
extern object __glo_vector_91_125list;
extern object __glo_vector_91_125string;
extern object __glo_vector_91map;
extern object __glo_vector_91for_91each;
extern object __glo_make_91string;
extern object __glo_string;
extern object __glo_string_91copy;
extern object __glo_string_91copy_67;
extern object __glo_string_91fill_67;
extern object __glo_string_91_125list;
extern object __glo_string_91_125vector;
extern object __glo_string_91map;
extern object __glo_string_91for_91each;
extern object __glo_make_91parameter;
extern object __glo_current_91output_91port;
extern object __glo_current_91input_91port;
extern object __glo_current_91error_91port;
extern object __glo_call_91with_91port;
extern object __glo_error;
extern object __glo_raise;
extern object __glo_raise_91continuable;
extern object __glo_with_91exception_91handler;
extern object __glo__85exception_91handler_91stack_85;
extern object __glo_Cyc_91add_91exception_91handler;
extern object __glo_Cyc_91remove_91exception_91handler;
extern object __glo_newline;
extern object __glo_write_91char;
extern object __glo_flush_91output_91port;
extern object __glo_read_91line;
extern object __glo_features;
extern object __glo_any;
extern object __glo_every;
extern object __glo_and;
extern object __glo_or;
extern object __glo_let;
extern object __glo_let_85;
extern object __glo_letrec;
extern object __glo_begin;
extern object __glo__case;
extern object __glo_cond;
extern object __glo_cond_91expand;
extern object __glo_when;
extern object __glo_quasiquote;
extern object __glo_eval;
extern object __glo_create_91environment;
extern object __glo_tagged_91list_127;
extern object __glo_if_127;
extern object __glo_begin_127;
extern object __glo_lambda_127;
extern object __glo_Cyc_91er_91rename;
extern object __glo_Cyc_91er_91compare_127;
extern object __glo_mangle;
extern object __glo_mangle_91global;
extern object __glo_gensym;
extern object __glo_delete;
extern object __glo_delete_91duplicates;
extern object __glo_list_91insert_91at_67;
extern object __glo_filter;
#include "cyclone/runtime.h"
defsymbol(macro);
defsymbol(quote);
defsymbol(define_91syntax);
static void __lambda_45(int argc, closure _,object k_7317) ;
static void __lambda_44(int argc, object self_7364, object r_7318) ;
static void __lambda_43(int argc, object self_7365, object r_7319) ;
static void __lambda_42(int argc, closure _,object k_7322, object exp_732, object defined_91macros_731) ;
static void __lambda_41(int argc, object self_7366, object r_7344) ;
static void __lambda_40(int argc, object self_7367, object r_7323) ;
static void __lambda_39(int argc, object self_7368, object macro_733) ;
static void __lambda_38(int argc, object self_7369, object r_7343) ;
static void __lambda_37(int argc, object self_7370, object r_7342) ;
static void __lambda_36(int argc, object self_7371, object r_7339) ;
static void __lambda_35(int argc, object self_7372, object tmp_734) ;
static void __lambda_34(int argc, object self_7373, object r_7324) ;
static void __lambda_33(int argc, object self_7374, object compiled_91macro_127_735) ;
static void __lambda_32(int argc, object self_7375) ;
static void __lambda_31(int argc, object self_7376, object r_7325) ;
static void __lambda_30(int argc, object self_7377) ;
static void __lambda_29(int argc, object self_7378, object r_7328) ;
static void __lambda_28(int argc, object self_7379, object env_91vars_736) ;
static void __lambda_27(int argc, object self_7380, object k_7336, object v_737) ;
static void __lambda_26(int argc, object self_7381, object r_7337) ;
static void __lambda_25(int argc, object self_7382, object r_7338) ;
static void __lambda_24(int argc, object self_7383, object r_7335) ;
static void __lambda_23(int argc, object self_7384, object r_7329) ;
static void __lambda_22(int argc, object self_7385, object env_91vals_738) ;
static void __lambda_21(int argc, object self_7386, object r_7330) ;
static void __lambda_20(int argc, object self_7387, object env_739) ;
static void __lambda_19(int argc, object self_7388) ;
static void __lambda_18(int argc, object self_7389, object r_7332) ;
static void __lambda_17(int argc, object self_7390, object r_7334) ;
static void __lambda_16(int argc, object self_7391, object r_7333) ;
static void __lambda_15(int argc, object self_7392, object r_7331) ;
static void __lambda_14(int argc, object self_7393) ;
static void __lambda_13(int argc, object self_7394, object r_7327) ;
static void __lambda_12(int argc, object self_7395, object r_7326) ;
static void __lambda_11(int argc, object self_7396) ;
static void __lambda_10(int argc, object self_7397, object k_7340) ;
static void __lambda_9(int argc, object self_7398, object r_7341) ;
static void __lambda_8(int argc, closure _,object k_7347, object exp_7311, object defined_91macros_7310) ;
static void __lambda_7(int argc, object self_7399, object r_7348) ;
static void __lambda_6(int argc, closure _,object k_7351, object exp_7312) ;
static void __lambda_5(int argc, object self_73100, object r_7352) ;
static void __lambda_4(int argc, closure _,object k_7355) ;
static void __lambda_3(int argc, closure _,object k_7358, object name_7314, object body_7313) ;
static void __lambda_2(int argc, object self_73101, object r_7361) ;
static void __lambda_1(int argc, object self_73102, object r_7360) ;
static void __lambda_0(int argc, object self_73103, object r_7359) ;

static void __lambda_45(int argc, closure _,object k_7317) {
  Cyc_st_add("scheme/cyclone/macros.sld:lib-init:schemecyclonemacros");

closureN_type c_73258;
c_73258.tag = closureN_tag;
 c_73258.fn = (function_type)__lambda_44;
c_73258.num_args = 1;
c_73258.num_elt = 1;
c_73258.elts = (object *)alloca(sizeof(object) * 1);
c_73258.elts[0] = k_7317;


make_int(c_73265, 0);
return_closcall1((closure)&c_73258,  &c_73265);; 
}

static void __lambda_44(int argc, object self_7364, object r_7318) {
  Cyc_st_add("scheme/cyclone/macros.sld:lib-init:schemecyclonemacros");

closureN_type c_73260;
c_73260.tag = closureN_tag;
 c_73260.fn = (function_type)__lambda_43;
c_73260.num_args = 1;
c_73260.num_elt = 1;
c_73260.elts = (object *)alloca(sizeof(object) * 1);
c_73260.elts[0] = ((closureN)self_7364)->elts[0];

return_closcall1((closure)&c_73260,  nil);; 
}

static void __lambda_43(int argc, object self_7365, object r_7319) {
  Cyc_st_add("scheme/cyclone/macros.sld:lib-init:schemecyclonemacros");
return_closcall1(  ((closureN)self_7365)->elts[0],  global_set(__glo__85macro_117defined_91macros_85, r_7319));; 
}

static void __lambda_42(int argc, closure _,object k_7322, object exp_732, object defined_91macros_731) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73141;
c_73141.tag = closureN_tag;
 c_73141.fn = (function_type)__lambda_41;
c_73141.num_args = 1;
c_73141.num_elt = 3;
c_73141.elts = (object *)alloca(sizeof(object) * 3);
c_73141.elts[0] = defined_91macros_731;
c_73141.elts[1] = exp_732;
c_73141.elts[2] = k_7322;

return_closcall1((closure)&c_73141,  car(exp_732));; 
}

static void __lambda_41(int argc, object self_7366, object r_7344) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73143;
c_73143.tag = closureN_tag;
 c_73143.fn = (function_type)__lambda_40;
c_73143.num_args = 1;
c_73143.num_elt = 3;
c_73143.elts = (object *)alloca(sizeof(object) * 3);
c_73143.elts[0] = ((closureN)self_7366)->elts[0];
c_73143.elts[1] = ((closureN)self_7366)->elts[1];
c_73143.elts[2] = ((closureN)self_7366)->elts[2];

return_closcall1((closure)&c_73143,  assoc(r_7344, ((closureN)self_7366)->elts[0]));; 
}

static void __lambda_40(int argc, object self_7367, object r_7323) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73145;
c_73145.tag = closureN_tag;
 c_73145.fn = (function_type)__lambda_39;
c_73145.num_args = 1;
c_73145.num_elt = 3;
c_73145.elts = (object *)alloca(sizeof(object) * 3);
c_73145.elts[0] = ((closureN)self_7367)->elts[0];
c_73145.elts[1] = ((closureN)self_7367)->elts[1];
c_73145.elts[2] = ((closureN)self_7367)->elts[2];

return_closcall1((closure)&c_73145,  r_7323);; 
}

static void __lambda_39(int argc, object self_7368, object macro_733) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73147;
c_73147.tag = closureN_tag;
 c_73147.fn = (function_type)__lambda_38;
c_73147.num_args = 1;
c_73147.num_elt = 4;
c_73147.elts = (object *)alloca(sizeof(object) * 4);
c_73147.elts[0] = ((closureN)self_7368)->elts[0];
c_73147.elts[1] = ((closureN)self_7368)->elts[1];
c_73147.elts[2] = ((closureN)self_7368)->elts[2];
c_73147.elts[3] = macro_733;

return_closcall1((closure)&c_73147,  cdr(macro_733));; 
}

static void __lambda_38(int argc, object self_7369, object r_7343) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73149;
c_73149.tag = closureN_tag;
 c_73149.fn = (function_type)__lambda_37;
c_73149.num_args = 1;
c_73149.num_elt = 4;
c_73149.elts = (object *)alloca(sizeof(object) * 4);
c_73149.elts[0] = ((closureN)self_7369)->elts[0];
c_73149.elts[1] = ((closureN)self_7369)->elts[1];
c_73149.elts[2] = ((closureN)self_7369)->elts[2];
c_73149.elts[3] = ((closureN)self_7369)->elts[3];

return_closcall1((closure)&c_73149,  Cyc_get_cvar(r_7343));; 
}

static void __lambda_37(int argc, object self_7370, object r_7342) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73151;
c_73151.tag = closureN_tag;
 c_73151.fn = (function_type)__lambda_36;
c_73151.num_args = 1;
c_73151.num_elt = 4;
c_73151.elts = (object *)alloca(sizeof(object) * 4);
c_73151.elts[0] = ((closureN)self_7370)->elts[0];
c_73151.elts[1] = ((closureN)self_7370)->elts[1];
c_73151.elts[2] = ((closureN)self_7370)->elts[2];
c_73151.elts[3] = ((closureN)self_7370)->elts[3];

return_closcall1((closure)&c_73151,  Cyc_is_macro(r_7342));; 
}

static void __lambda_36(int argc, object self_7371, object r_7339) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73153;
c_73153.tag = closureN_tag;
 c_73153.fn = (function_type)__lambda_35;
c_73153.num_args = 1;
c_73153.num_elt = 4;
c_73153.elts = (object *)alloca(sizeof(object) * 4);
c_73153.elts[0] = ((closureN)self_7371)->elts[0];
c_73153.elts[1] = ((closureN)self_7371)->elts[1];
c_73153.elts[2] = ((closureN)self_7371)->elts[2];
c_73153.elts[3] = ((closureN)self_7371)->elts[3];

return_closcall1((closure)&c_73153,  r_7339);; 
}

static void __lambda_35(int argc, object self_7372, object tmp_734) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73155;
c_73155.tag = closureN_tag;
 c_73155.fn = (function_type)__lambda_10;
c_73155.num_args = 0;
c_73155.num_elt = 2;
c_73155.elts = (object *)alloca(sizeof(object) * 2);
c_73155.elts[0] = ((closureN)self_7372)->elts[3];
c_73155.elts[1] = tmp_734;


closureN_type c_73168;
c_73168.tag = closureN_tag;
 c_73168.fn = (function_type)__lambda_34;
c_73168.num_args = 1;
c_73168.num_elt = 4;
c_73168.elts = (object *)alloca(sizeof(object) * 4);
c_73168.elts[0] = ((closureN)self_7372)->elts[0];
c_73168.elts[1] = ((closureN)self_7372)->elts[1];
c_73168.elts[2] = ((closureN)self_7372)->elts[2];
c_73168.elts[3] = ((closureN)self_7372)->elts[3];

return_closcall1((closure)&c_73155,  &c_73168);; 
}

static void __lambda_34(int argc, object self_7373, object r_7324) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73170;
c_73170.tag = closureN_tag;
 c_73170.fn = (function_type)__lambda_33;
c_73170.num_args = 1;
c_73170.num_elt = 4;
c_73170.elts = (object *)alloca(sizeof(object) * 4);
c_73170.elts[0] = ((closureN)self_7373)->elts[0];
c_73170.elts[1] = ((closureN)self_7373)->elts[1];
c_73170.elts[2] = ((closureN)self_7373)->elts[2];
c_73170.elts[3] = ((closureN)self_7373)->elts[3];

return_closcall1((closure)&c_73170,  r_7324);; 
}

static void __lambda_33(int argc, object self_7374, object compiled_91macro_127_735) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73172;
c_73172.tag = closureN_tag;
 c_73172.fn = (function_type)__lambda_32;
c_73172.num_args = 0;
c_73172.num_elt = 5;
c_73172.elts = (object *)alloca(sizeof(object) * 5);
c_73172.elts[0] = compiled_91macro_127_735;
c_73172.elts[1] = ((closureN)self_7374)->elts[0];
c_73172.elts[2] = ((closureN)self_7374)->elts[1];
c_73172.elts[3] = ((closureN)self_7374)->elts[2];
c_73172.elts[4] = ((closureN)self_7374)->elts[3];

return_closcall0((closure)&c_73172);; 
}

static void __lambda_32(int argc, object self_7375) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73174;
c_73174.tag = closureN_tag;
 c_73174.fn = (function_type)__lambda_31;
c_73174.num_args = 1;
c_73174.num_elt = 5;
c_73174.elts = (object *)alloca(sizeof(object) * 5);
c_73174.elts[0] = ((closureN)self_7375)->elts[0];
c_73174.elts[1] = ((closureN)self_7375)->elts[1];
c_73174.elts[2] = ((closureN)self_7375)->elts[2];
c_73174.elts[3] = ((closureN)self_7375)->elts[3];
c_73174.elts[4] = ((closureN)self_7375)->elts[4];

return_closcall2(  __glo_not,  &c_73174, ((closureN)self_7375)->elts[4]);; 
}

static void __lambda_31(int argc, object self_7376, object r_7325) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");
if( !eq(boolean_f, r_7325) ){ 
  
closureN_type c_73176;
c_73176.tag = closureN_tag;
 c_73176.fn = (function_type)__lambda_11;
c_73176.num_args = 0;
c_73176.num_elt = 2;
c_73176.elts = (object *)alloca(sizeof(object) * 2);
c_73176.elts[0] = ((closureN)self_7376)->elts[2];
c_73176.elts[1] = ((closureN)self_7376)->elts[3];

return_closcall0((closure)&c_73176);
} else { 
  if( !eq(boolean_f, ((closureN)self_7376)->elts[0]) ){ 
  
closureN_type c_73183;
c_73183.tag = closureN_tag;
 c_73183.fn = (function_type)__lambda_14;
c_73183.num_args = 0;
c_73183.num_elt = 3;
c_73183.elts = (object *)alloca(sizeof(object) * 3);
c_73183.elts[0] = ((closureN)self_7376)->elts[2];
c_73183.elts[1] = ((closureN)self_7376)->elts[3];
c_73183.elts[2] = ((closureN)self_7376)->elts[4];

return_closcall0((closure)&c_73183);
} else { 
  
closureN_type c_73197;
c_73197.tag = closureN_tag;
 c_73197.fn = (function_type)__lambda_30;
c_73197.num_args = 0;
c_73197.num_elt = 4;
c_73197.elts = (object *)alloca(sizeof(object) * 4);
c_73197.elts[0] = ((closureN)self_7376)->elts[1];
c_73197.elts[1] = ((closureN)self_7376)->elts[2];
c_73197.elts[2] = ((closureN)self_7376)->elts[3];
c_73197.elts[3] = ((closureN)self_7376)->elts[4];

return_closcall0((closure)&c_73197);}
}
; 
}

static void __lambda_30(int argc, object self_7377) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73199;
c_73199.tag = closureN_tag;
 c_73199.fn = (function_type)__lambda_29;
c_73199.num_args = 1;
c_73199.num_elt = 4;
c_73199.elts = (object *)alloca(sizeof(object) * 4);
c_73199.elts[0] = ((closureN)self_7377)->elts[0];
c_73199.elts[1] = ((closureN)self_7377)->elts[1];
c_73199.elts[2] = ((closureN)self_7377)->elts[2];
c_73199.elts[3] = ((closureN)self_7377)->elts[3];

return_closcall3(  __glo_map,  &c_73199, primitive_car, ((closureN)self_7377)->elts[0]);; 
}

static void __lambda_29(int argc, object self_7378, object r_7328) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73201;
c_73201.tag = closureN_tag;
 c_73201.fn = (function_type)__lambda_28;
c_73201.num_args = 1;
c_73201.num_elt = 4;
c_73201.elts = (object *)alloca(sizeof(object) * 4);
c_73201.elts[0] = ((closureN)self_7378)->elts[0];
c_73201.elts[1] = ((closureN)self_7378)->elts[1];
c_73201.elts[2] = ((closureN)self_7378)->elts[2];
c_73201.elts[3] = ((closureN)self_7378)->elts[3];

return_closcall1((closure)&c_73201,  r_7328);; 
}

static void __lambda_28(int argc, object self_7379, object env_91vars_736) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73203;
c_73203.tag = closureN_tag;
 c_73203.fn = (function_type)__lambda_24;
c_73203.num_args = 1;
c_73203.num_elt = 5;
c_73203.elts = (object *)alloca(sizeof(object) * 5);
c_73203.elts[0] = ((closureN)self_7379)->elts[0];
c_73203.elts[1] = env_91vars_736;
c_73203.elts[2] = ((closureN)self_7379)->elts[1];
c_73203.elts[3] = ((closureN)self_7379)->elts[2];
c_73203.elts[4] = ((closureN)self_7379)->elts[3];


mclosure0(c_73232, (function_type)__lambda_27);c_73232.num_args = 1;
return_closcall1((closure)&c_73203,  &c_73232);; 
}

static void __lambda_27(int argc, object self_7380, object k_7336, object v_737) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73234;
c_73234.tag = closureN_tag;
 c_73234.fn = (function_type)__lambda_26;
c_73234.num_args = 1;
c_73234.num_elt = 2;
c_73234.elts = (object *)alloca(sizeof(object) * 2);
c_73234.elts[0] = k_7336;
c_73234.elts[1] = v_737;

return_closcall1((closure)&c_73234,  quote_macro);; 
}

static void __lambda_26(int argc, object self_7381, object r_7337) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73236;
c_73236.tag = closureN_tag;
 c_73236.fn = (function_type)__lambda_25;
c_73236.num_args = 1;
c_73236.num_elt = 2;
c_73236.elts = (object *)alloca(sizeof(object) * 2);
c_73236.elts[0] = ((closureN)self_7381)->elts[0];
c_73236.elts[1] = r_7337;

return_closcall1((closure)&c_73236,  cdr(((closureN)self_7381)->elts[1]));; 
}

static void __lambda_25(int argc, object self_7382, object r_7338) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");
return_closcall3(  __glo__list,  ((closureN)self_7382)->elts[0], ((closureN)self_7382)->elts[1], r_7338);; 
}

static void __lambda_24(int argc, object self_7383, object r_7335) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73205;
c_73205.tag = closureN_tag;
 c_73205.fn = (function_type)__lambda_23;
c_73205.num_args = 1;
c_73205.num_elt = 4;
c_73205.elts = (object *)alloca(sizeof(object) * 4);
c_73205.elts[0] = ((closureN)self_7383)->elts[1];
c_73205.elts[1] = ((closureN)self_7383)->elts[2];
c_73205.elts[2] = ((closureN)self_7383)->elts[3];
c_73205.elts[3] = ((closureN)self_7383)->elts[4];

return_closcall3(  __glo_map,  &c_73205, r_7335, ((closureN)self_7383)->elts[0]);; 
}

static void __lambda_23(int argc, object self_7384, object r_7329) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73207;
c_73207.tag = closureN_tag;
 c_73207.fn = (function_type)__lambda_22;
c_73207.num_args = 1;
c_73207.num_elt = 4;
c_73207.elts = (object *)alloca(sizeof(object) * 4);
c_73207.elts[0] = ((closureN)self_7384)->elts[0];
c_73207.elts[1] = ((closureN)self_7384)->elts[1];
c_73207.elts[2] = ((closureN)self_7384)->elts[2];
c_73207.elts[3] = ((closureN)self_7384)->elts[3];

return_closcall1((closure)&c_73207,  r_7329);; 
}

static void __lambda_22(int argc, object self_7385, object env_91vals_738) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73209;
c_73209.tag = closureN_tag;
 c_73209.fn = (function_type)__lambda_21;
c_73209.num_args = 1;
c_73209.num_elt = 3;
c_73209.elts = (object *)alloca(sizeof(object) * 3);
c_73209.elts[0] = ((closureN)self_7385)->elts[1];
c_73209.elts[1] = ((closureN)self_7385)->elts[2];
c_73209.elts[2] = ((closureN)self_7385)->elts[3];

return_closcall3(  __glo_create_91environment,  &c_73209, ((closureN)self_7385)->elts[0], env_91vals_738);; 
}

static void __lambda_21(int argc, object self_7386, object r_7330) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73211;
c_73211.tag = closureN_tag;
 c_73211.fn = (function_type)__lambda_20;
c_73211.num_args = 1;
c_73211.num_elt = 3;
c_73211.elts = (object *)alloca(sizeof(object) * 3);
c_73211.elts[0] = ((closureN)self_7386)->elts[0];
c_73211.elts[1] = ((closureN)self_7386)->elts[1];
c_73211.elts[2] = ((closureN)self_7386)->elts[2];

return_closcall1((closure)&c_73211,  r_7330);; 
}

static void __lambda_20(int argc, object self_7387, object env_739) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73213;
c_73213.tag = closureN_tag;
 c_73213.fn = (function_type)__lambda_19;
c_73213.num_args = 0;
c_73213.num_elt = 4;
c_73213.elts = (object *)alloca(sizeof(object) * 4);
c_73213.elts[0] = env_739;
c_73213.elts[1] = ((closureN)self_7387)->elts[0];
c_73213.elts[2] = ((closureN)self_7387)->elts[1];
c_73213.elts[3] = ((closureN)self_7387)->elts[2];

return_closcall0((closure)&c_73213);; 
}

static void __lambda_19(int argc, object self_7388) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73215;
c_73215.tag = closureN_tag;
 c_73215.fn = (function_type)__lambda_18;
c_73215.num_args = 1;
c_73215.num_elt = 3;
c_73215.elts = (object *)alloca(sizeof(object) * 3);
c_73215.elts[0] = ((closureN)self_7388)->elts[0];
c_73215.elts[1] = ((closureN)self_7388)->elts[1];
c_73215.elts[2] = ((closureN)self_7388)->elts[2];

return_closcall1((closure)&c_73215,  cdr(((closureN)self_7388)->elts[3]));; 
}

static void __lambda_18(int argc, object self_7389, object r_7332) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73217;
c_73217.tag = closureN_tag;
 c_73217.fn = (function_type)__lambda_17;
c_73217.num_args = 1;
c_73217.num_elt = 4;
c_73217.elts = (object *)alloca(sizeof(object) * 4);
c_73217.elts[0] = ((closureN)self_7389)->elts[0];
c_73217.elts[1] = ((closureN)self_7389)->elts[1];
c_73217.elts[2] = ((closureN)self_7389)->elts[2];
c_73217.elts[3] = r_7332;

return_closcall1((closure)&c_73217,  quote_quote);; 
}

static void __lambda_17(int argc, object self_7390, object r_7334) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73219;
c_73219.tag = closureN_tag;
 c_73219.fn = (function_type)__lambda_16;
c_73219.num_args = 1;
c_73219.num_elt = 3;
c_73219.elts = (object *)alloca(sizeof(object) * 3);
c_73219.elts[0] = ((closureN)self_7390)->elts[0];
c_73219.elts[1] = ((closureN)self_7390)->elts[2];
c_73219.elts[2] = ((closureN)self_7390)->elts[3];

return_closcall3(  __glo__list,  &c_73219, r_7334, ((closureN)self_7390)->elts[1]);; 
}

static void __lambda_16(int argc, object self_7391, object r_7333) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73221;
c_73221.tag = closureN_tag;
 c_73221.fn = (function_type)__lambda_15;
c_73221.num_args = 1;
c_73221.num_elt = 2;
c_73221.elts = (object *)alloca(sizeof(object) * 2);
c_73221.elts[0] = ((closureN)self_7391)->elts[0];
c_73221.elts[1] = ((closureN)self_7391)->elts[1];

return_closcall5(  __glo__list,  &c_73221, ((closureN)self_7391)->elts[2], r_7333, __glo_Cyc_91er_91rename, __glo_Cyc_91er_91compare_127);; 
}

static void __lambda_15(int argc, object self_7392, object r_7331) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");
return_closcall3(  __glo_eval,  ((closureN)self_7392)->elts[1], r_7331, ((closureN)self_7392)->elts[0]);; 
}

static void __lambda_14(int argc, object self_7393) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73185;
c_73185.tag = closureN_tag;
 c_73185.fn = (function_type)__lambda_13;
c_73185.num_args = 1;
c_73185.num_elt = 2;
c_73185.elts = (object *)alloca(sizeof(object) * 2);
c_73185.elts[0] = ((closureN)self_7393)->elts[0];
c_73185.elts[1] = ((closureN)self_7393)->elts[1];

return_closcall1((closure)&c_73185,  cdr(((closureN)self_7393)->elts[2]));; 
}

static void __lambda_13(int argc, object self_7394, object r_7327) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

closureN_type c_73187;
c_73187.tag = closureN_tag;
 c_73187.fn = (function_type)__lambda_12;
c_73187.num_args = 1;
c_73187.num_elt = 2;
c_73187.elts = (object *)alloca(sizeof(object) * 2);
c_73187.elts[0] = ((closureN)self_7394)->elts[0];
c_73187.elts[1] = ((closureN)self_7394)->elts[1];

return_closcall1((closure)&c_73187,  Cyc_get_cvar(r_7327));; 
}

static void __lambda_12(int argc, object self_7395, object r_7326) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");
return_closcall4(  r_7326,  ((closureN)self_7395)->elts[1], ((closureN)self_7395)->elts[0], __glo_Cyc_91er_91rename, __glo_Cyc_91er_91compare_127);; 
}

static void __lambda_11(int argc, object self_7396) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");

make_string(c_73179, "macro not found");
return_closcall3(  __glo_error,  ((closureN)self_7396)->elts[1], &c_73179, ((closureN)self_7396)->elts[0]);; 
}

static void __lambda_10(int argc, object self_7397, object k_7340) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");
if( !eq(boolean_f, ((closureN)self_7397)->elts[1]) ){ 
  return_closcall1(  k_7340,  ((closureN)self_7397)->elts[1]);
} else { 
  
closureN_type c_73160;
c_73160.tag = closureN_tag;
 c_73160.fn = (function_type)__lambda_9;
c_73160.num_args = 1;
c_73160.num_elt = 1;
c_73160.elts = (object *)alloca(sizeof(object) * 1);
c_73160.elts[0] = k_7340;

return_closcall1((closure)&c_73160,  cdr(((closureN)self_7397)->elts[0]));}
; 
}

static void __lambda_9(int argc, object self_7398, object r_7341) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:expand");
return_closcall1(  ((closureN)self_7398)->elts[0],  Cyc_is_procedure(r_7341));; 
}

static void __lambda_8(int argc, closure _,object k_7347, object exp_7311, object defined_91macros_7310) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:macro?");

closureN_type c_73131;
c_73131.tag = closureN_tag;
 c_73131.fn = (function_type)__lambda_7;
c_73131.num_args = 1;
c_73131.num_elt = 2;
c_73131.elts = (object *)alloca(sizeof(object) * 2);
c_73131.elts[0] = defined_91macros_7310;
c_73131.elts[1] = k_7347;

return_closcall1((closure)&c_73131,  car(exp_7311));; 
}

static void __lambda_7(int argc, object self_7399, object r_7348) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:macro?");
return_closcall1(  ((closureN)self_7399)->elts[1],  assoc(r_7348, ((closureN)self_7399)->elts[0]));; 
}

static void __lambda_6(int argc, closure _,object k_7351, object exp_7312) {
  Cyc_st_add("scheme/cyclone/macros.sld:define-syntax?");

closureN_type c_73125;
c_73125.tag = closureN_tag;
 c_73125.fn = (function_type)__lambda_5;
c_73125.num_args = 1;
c_73125.num_elt = 2;
c_73125.elts = (object *)alloca(sizeof(object) * 2);
c_73125.elts[0] = exp_7312;
c_73125.elts[1] = k_7351;

return_closcall1((closure)&c_73125,  quote_define_91syntax);; 
}

static void __lambda_5(int argc, object self_73100, object r_7352) {
  Cyc_st_add("scheme/cyclone/macros.sld:define-syntax?");
return_closcall3(  __glo_tagged_91list_127,  ((closureN)self_73100)->elts[1], r_7352, ((closureN)self_73100)->elts[0]);; 
}

static void __lambda_4(int argc, closure _,object k_7355) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:get-defined-macros");
return_closcall1(  k_7355,  __glo__85macro_117defined_91macros_85);; 
}

static void __lambda_3(int argc, closure _,object k_7358, object name_7314, object body_7313) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:add!");

closureN_type c_73106;
c_73106.tag = closureN_tag;
 c_73106.fn = (function_type)__lambda_2;
c_73106.num_args = 1;
c_73106.num_elt = 1;
c_73106.elts = (object *)alloca(sizeof(object) * 1);
c_73106.elts[0] = k_7358;


make_cons(c_73120,name_7314, body_7313);
return_closcall1((closure)&c_73106,  &c_73120);; 
}

static void __lambda_2(int argc, object self_73101, object r_7361) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:add!");

closureN_type c_73108;
c_73108.tag = closureN_tag;
 c_73108.fn = (function_type)__lambda_1;
c_73108.num_args = 1;
c_73108.num_elt = 1;
c_73108.elts = (object *)alloca(sizeof(object) * 1);
c_73108.elts[0] = ((closureN)self_73101)->elts[0];


make_cons(c_73117,r_7361, __glo__85macro_117defined_91macros_85);
return_closcall1((closure)&c_73108,  &c_73117);; 
}

static void __lambda_1(int argc, object self_73102, object r_7360) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:add!");

closureN_type c_73110;
c_73110.tag = closureN_tag;
 c_73110.fn = (function_type)__lambda_0;
c_73110.num_args = 1;
c_73110.num_elt = 1;
c_73110.elts = (object *)alloca(sizeof(object) * 1);
c_73110.elts[0] = ((closureN)self_73102)->elts[0];

return_closcall1((closure)&c_73110,  global_set(__glo__85macro_117defined_91macros_85, r_7360));; 
}

static void __lambda_0(int argc, object self_73103, object r_7359) {
  Cyc_st_add("scheme/cyclone/macros.sld:macro:add!");
return_closcall1(  ((closureN)self_73103)->elts[0],  boolean_t);; 
}

void c_schemecyclonemacros_entry_pt(argc, cont,value) int argc; closure cont; object value;{ 
  quote_macro = find_or_add_symbol("macro");
  quote_quote = find_or_add_symbol("quote");
  quote_define_91syntax = find_or_add_symbol("define-syntax");

  add_global((object *) &__glo_lib_91init_117schemecyclonemacros);
  add_global((object *) &__glo_macro_117expand);
  add_global((object *) &__glo_macro_117macro_127);
  add_global((object *) &__glo_define_91syntax_127);
  add_global((object *) &__glo_macro_117get_91defined_91macros);
  add_global((object *) &__glo_macro_117add_67);
  add_global((object *) &__glo__85macro_117defined_91macros_85);
  add_symbol(quote_macro);
  add_symbol(quote_quote);
  add_symbol(quote_define_91syntax);
  mclosure0(c_73256, (function_type)__lambda_45);c_73256.num_args = 0; 
  __glo_lib_91init_117schemecyclonemacros = &c_73256; 
  mclosure0(c_73139, (function_type)__lambda_42);c_73139.num_args = 2; 
  __glo_macro_117expand = &c_73139; 
  mclosure0(c_73129, (function_type)__lambda_8);c_73129.num_args = 2; 
  __glo_macro_117macro_127 = &c_73129; 
  mclosure0(c_73123, (function_type)__lambda_6);c_73123.num_args = 1; 
  __glo_define_91syntax_127 = &c_73123; 
  mclosure0(c_73121, (function_type)__lambda_4);c_73121.num_args = 0; 
  __glo_macro_117get_91defined_91macros = &c_73121; 
  mclosure0(c_73104, (function_type)__lambda_3);c_73104.num_args = 2; 
  __glo_macro_117add_67 = &c_73104; 
  __glo__85macro_117defined_91macros_85 = boolean_f; 

  make_cvar(cvar_73266, (object *)&__glo_lib_91init_117schemecyclonemacros);make_cons(pair_73267, find_or_add_symbol("lib-init:schemecyclonemacros"), &cvar_73266);
  make_cvar(cvar_73268, (object *)&__glo_macro_117expand);make_cons(pair_73269, find_or_add_symbol("macro:expand"), &cvar_73268);
  make_cvar(cvar_73270, (object *)&__glo_macro_117macro_127);make_cons(pair_73271, find_or_add_symbol("macro:macro?"), &cvar_73270);
  make_cvar(cvar_73272, (object *)&__glo_define_91syntax_127);make_cons(pair_73273, find_or_add_symbol("define-syntax?"), &cvar_73272);
  make_cvar(cvar_73274, (object *)&__glo_macro_117get_91defined_91macros);make_cons(pair_73275, find_or_add_symbol("macro:get-defined-macros"), &cvar_73274);
  make_cvar(cvar_73276, (object *)&__glo_macro_117add_67);make_cons(pair_73277, find_or_add_symbol("macro:add!"), &cvar_73276);
  make_cvar(cvar_73278, (object *)&__glo__85macro_117defined_91macros_85);make_cons(pair_73279, find_or_add_symbol("*macro:defined-macros*"), &cvar_73278);
make_cons(c_73280, &pair_73267,Cyc_global_variables);
make_cons(c_73281, &pair_73269, &c_73280);
make_cons(c_73282, &pair_73271, &c_73281);
make_cons(c_73283, &pair_73273, &c_73282);
make_cons(c_73284, &pair_73275, &c_73283);
make_cons(c_73285, &pair_73277, &c_73284);
make_cons(c_73286, &pair_73279, &c_73285);
Cyc_global_variables = &c_73286;
cont = ((closure1_type *)cont)->elt1;
(((closure)__glo_lib_91init_117schemecyclonemacros)->fn)(1, cont, cont);
}
