/**
 ** This file was automatically generated by the Cyclone scheme compiler
 ** http://justinethier.github.io/cyclone/
 **
 ** (c) 2014-2016 Justin Ethier
 ** Version 0.3.2 (beta)
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
object __glo_lib_91init_117schemecxr_scheme_cxr = NULL;
object __glo_caaaaar_scheme_cxr = NULL;
object __glo_cddddr_scheme_cxr = NULL;
object __glo_cdddar_scheme_cxr = NULL;
object __glo_cddadr_scheme_cxr = NULL;
object __glo_cddaar_scheme_cxr = NULL;
object __glo_cdaddr_scheme_cxr = NULL;
object __glo_cdadar_scheme_cxr = NULL;
object __glo_cdaadr_scheme_cxr = NULL;
object __glo_cdaaar_scheme_cxr = NULL;
object __glo_cadddr_scheme_cxr = NULL;
object __glo_caddar_scheme_cxr = NULL;
object __glo_cadadr_scheme_cxr = NULL;
object __glo_cadaar_scheme_cxr = NULL;
object __glo_caaddr_scheme_cxr = NULL;
object __glo_caadar_scheme_cxr = NULL;
object __glo_caaadr_scheme_cxr = NULL;
object __glo_caaaar_scheme_cxr = NULL;
object __glo_cdddr_scheme_cxr = NULL;
object __glo_cddar_scheme_cxr = NULL;
object __glo_cdadr_scheme_cxr = NULL;
object __glo_cdaar_scheme_cxr = NULL;
object __glo_caddr_scheme_cxr = NULL;
object __glo_cadar_scheme_cxr = NULL;
object __glo_caadr_scheme_cxr = NULL;
object __glo_caaar_scheme_cxr = NULL;
object __glo_cddr_scheme_cxr = NULL;
object __glo_cdar_scheme_cxr = NULL;
object __glo_cadr_scheme_cxr = NULL;
object __glo_caar_scheme_cxr = NULL;
#include "cyclone/runtime.h"
static void __lambda_57(void *data, int argc, closure _,object k_7332) ;
static void __lambda_56(void *data, int argc, closure _,object k_7335, object lis_731) ;
static void __lambda_55(void *data, int argc, closure _,object k_7342, object lis_732) ;
static void __lambda_54(void *data, int argc, object self_73220, object r_7346) ;
static void __lambda_53(void *data, int argc, closure _,object k_7349, object lis_733) ;
static void __lambda_52(void *data, int argc, object self_73221, object r_7353) ;
static void __lambda_51(void *data, int argc, closure _,object k_7356, object lis_734) ;
static void __lambda_50(void *data, int argc, object self_73222, object r_7360) ;
static void __lambda_49(void *data, int argc, closure _,object k_7363, object lis_735) ;
static void __lambda_48(void *data, int argc, object self_73223, object r_7367) ;
static void __lambda_47(void *data, int argc, closure _,object k_7370, object lis_736) ;
static void __lambda_46(void *data, int argc, object self_73224, object r_7374) ;
static void __lambda_45(void *data, int argc, closure _,object k_7377, object lis_737) ;
static void __lambda_44(void *data, int argc, object self_73225, object r_7381) ;
static void __lambda_43(void *data, int argc, closure _,object k_7384, object lis_738) ;
static void __lambda_42(void *data, int argc, object self_73226, object r_7388) ;
static void __lambda_41(void *data, int argc, closure _,object k_7391, object lis_739) ;
static void __lambda_40(void *data, int argc, object self_73227, object r_7395) ;
static void __lambda_39(void *data, int argc, closure _,object k_7398, object lis_7310) ;
static void __lambda_38(void *data, int argc, object self_73228, object r_73102) ;
static void __lambda_37(void *data, int argc, closure _,object k_73105, object lis_7311) ;
static void __lambda_36(void *data, int argc, object self_73229, object r_73109) ;
static void __lambda_35(void *data, int argc, closure _,object k_73112, object lis_7312) ;
static void __lambda_34(void *data, int argc, object self_73230, object r_73116) ;
static void __lambda_33(void *data, int argc, closure _,object k_73119, object lis_7313) ;
static void __lambda_32(void *data, int argc, object self_73231, object r_73123) ;
static void __lambda_31(void *data, int argc, closure _,object k_73126, object lis_7314) ;
static void __lambda_30(void *data, int argc, object self_73232, object r_73130) ;
static void __lambda_29(void *data, int argc, closure _,object k_73133, object lis_7315) ;
static void __lambda_28(void *data, int argc, object self_73233, object r_73137) ;
static void __lambda_27(void *data, int argc, closure _,object k_73140, object lis_7316) ;
static void __lambda_26(void *data, int argc, object self_73234, object r_73144) ;
static void __lambda_25(void *data, int argc, closure _,object k_73147, object lis_7317) ;
static void __lambda_24(void *data, int argc, object self_73235, object r_73151) ;
static void __lambda_23(void *data, int argc, closure _,object k_73154, object lis_7318) ;
static void __lambda_22(void *data, int argc, object self_73236, object r_73157) ;
static void __lambda_21(void *data, int argc, closure _,object k_73160, object lis_7319) ;
static void __lambda_20(void *data, int argc, object self_73237, object r_73163) ;
static void __lambda_19(void *data, int argc, closure _,object k_73166, object lis_7320) ;
static void __lambda_18(void *data, int argc, object self_73238, object r_73169) ;
static void __lambda_17(void *data, int argc, closure _,object k_73172, object lis_7321) ;
static void __lambda_16(void *data, int argc, object self_73239, object r_73175) ;
static void __lambda_15(void *data, int argc, closure _,object k_73178, object lis_7322) ;
static void __lambda_14(void *data, int argc, object self_73240, object r_73181) ;
static void __lambda_13(void *data, int argc, closure _,object k_73184, object lis_7323) ;
static void __lambda_12(void *data, int argc, object self_73241, object r_73187) ;
static void __lambda_11(void *data, int argc, closure _,object k_73190, object lis_7324) ;
static void __lambda_10(void *data, int argc, object self_73242, object r_73193) ;
static void __lambda_9(void *data, int argc, closure _,object k_73196, object lis_7325) ;
static void __lambda_8(void *data, int argc, object self_73243, object r_73199) ;
static void __lambda_7(void *data, int argc, closure _,object k_73202, object lis_7326) ;
static void __lambda_6(void *data, int argc, object self_73244, object r_73204) ;
static void __lambda_5(void *data, int argc, closure _,object k_73207, object lis_7327) ;
static void __lambda_4(void *data, int argc, object self_73245, object r_73209) ;
static void __lambda_3(void *data, int argc, closure _,object k_73212, object lis_7328) ;
static void __lambda_2(void *data, int argc, object self_73246, object r_73214) ;
static void __lambda_1(void *data, int argc, closure _,object k_73217, object lis_7329) ;
static void __lambda_0(void *data, int argc, object self_73247, object r_73219) ;

static void __lambda_57(void *data, int argc, closure _,object k_7332) {
  Cyc_st_add(data, "scheme/cxr.sld:lib-init:schemecxr");
return_closcall1(data,  k_7332,  obj_int2obj(0));; 
}

static void __lambda_56(void *data, int argc, closure _,object k_7335, object lis_731) {
  Cyc_st_add(data, "scheme/cxr.sld:caaaaar");
return_closcall1(data,  k_7335,  Cyc_car(data, Cyc_car(data, Cyc_car(data, Cyc_car(data, Cyc_car(data, lis_731))))));; 
}

static void __lambda_55(void *data, int argc, closure _,object k_7342, object lis_732) {
  Cyc_st_add(data, "scheme/cxr.sld:cddddr");

closureN_type c_73569;
c_73569.hdr.mark = gc_color_red;
 c_73569.hdr.grayed = 0;
c_73569.tag = closureN_tag;
 c_73569.fn = (function_type)__lambda_54;
c_73569.num_args = 1;
c_73569.num_elements = 1;
c_73569.elements = (object *)alloca(sizeof(object) * 1);
c_73569.elements[0] = k_7342;

return_closcall1(data,  lis_732,  &c_73569);; 
}

static void __lambda_54(void *data, int argc, object self_73220, object r_7346) {
  return_closcall1(data,  ((closureN)self_73220)->elements[0],  Cyc_cdr(data, Cyc_cdr(data, Cyc_cdr(data, Cyc_cdr(data, r_7346)))));; 
}

static void __lambda_53(void *data, int argc, closure _,object k_7349, object lis_733) {
  Cyc_st_add(data, "scheme/cxr.sld:cdddar");

closureN_type c_73556;
c_73556.hdr.mark = gc_color_red;
 c_73556.hdr.grayed = 0;
c_73556.tag = closureN_tag;
 c_73556.fn = (function_type)__lambda_52;
c_73556.num_args = 1;
c_73556.num_elements = 1;
c_73556.elements = (object *)alloca(sizeof(object) * 1);
c_73556.elements[0] = k_7349;

return_closcall1(data,  lis_733,  &c_73556);; 
}

static void __lambda_52(void *data, int argc, object self_73221, object r_7353) {
  return_closcall1(data,  ((closureN)self_73221)->elements[0],  Cyc_cdr(data, Cyc_cdr(data, Cyc_cdr(data, Cyc_car(data, r_7353)))));; 
}

static void __lambda_51(void *data, int argc, closure _,object k_7356, object lis_734) {
  Cyc_st_add(data, "scheme/cxr.sld:cddadr");

closureN_type c_73543;
c_73543.hdr.mark = gc_color_red;
 c_73543.hdr.grayed = 0;
c_73543.tag = closureN_tag;
 c_73543.fn = (function_type)__lambda_50;
c_73543.num_args = 1;
c_73543.num_elements = 1;
c_73543.elements = (object *)alloca(sizeof(object) * 1);
c_73543.elements[0] = k_7356;

return_closcall1(data,  lis_734,  &c_73543);; 
}

static void __lambda_50(void *data, int argc, object self_73222, object r_7360) {
  return_closcall1(data,  ((closureN)self_73222)->elements[0],  Cyc_cdr(data, Cyc_cdr(data, Cyc_car(data, Cyc_cdr(data, r_7360)))));; 
}

static void __lambda_49(void *data, int argc, closure _,object k_7363, object lis_735) {
  Cyc_st_add(data, "scheme/cxr.sld:cddaar");

closureN_type c_73530;
c_73530.hdr.mark = gc_color_red;
 c_73530.hdr.grayed = 0;
c_73530.tag = closureN_tag;
 c_73530.fn = (function_type)__lambda_48;
c_73530.num_args = 1;
c_73530.num_elements = 1;
c_73530.elements = (object *)alloca(sizeof(object) * 1);
c_73530.elements[0] = k_7363;

return_closcall1(data,  lis_735,  &c_73530);; 
}

static void __lambda_48(void *data, int argc, object self_73223, object r_7367) {
  return_closcall1(data,  ((closureN)self_73223)->elements[0],  Cyc_cdr(data, Cyc_cdr(data, Cyc_car(data, Cyc_car(data, r_7367)))));; 
}

static void __lambda_47(void *data, int argc, closure _,object k_7370, object lis_736) {
  Cyc_st_add(data, "scheme/cxr.sld:cdaddr");

closureN_type c_73517;
c_73517.hdr.mark = gc_color_red;
 c_73517.hdr.grayed = 0;
c_73517.tag = closureN_tag;
 c_73517.fn = (function_type)__lambda_46;
c_73517.num_args = 1;
c_73517.num_elements = 1;
c_73517.elements = (object *)alloca(sizeof(object) * 1);
c_73517.elements[0] = k_7370;

return_closcall1(data,  lis_736,  &c_73517);; 
}

static void __lambda_46(void *data, int argc, object self_73224, object r_7374) {
  return_closcall1(data,  ((closureN)self_73224)->elements[0],  Cyc_cdr(data, Cyc_car(data, Cyc_cdr(data, Cyc_cdr(data, r_7374)))));; 
}

static void __lambda_45(void *data, int argc, closure _,object k_7377, object lis_737) {
  Cyc_st_add(data, "scheme/cxr.sld:cdadar");

closureN_type c_73504;
c_73504.hdr.mark = gc_color_red;
 c_73504.hdr.grayed = 0;
c_73504.tag = closureN_tag;
 c_73504.fn = (function_type)__lambda_44;
c_73504.num_args = 1;
c_73504.num_elements = 1;
c_73504.elements = (object *)alloca(sizeof(object) * 1);
c_73504.elements[0] = k_7377;

return_closcall1(data,  lis_737,  &c_73504);; 
}

static void __lambda_44(void *data, int argc, object self_73225, object r_7381) {
  return_closcall1(data,  ((closureN)self_73225)->elements[0],  Cyc_cdr(data, Cyc_car(data, Cyc_cdr(data, Cyc_car(data, r_7381)))));; 
}

static void __lambda_43(void *data, int argc, closure _,object k_7384, object lis_738) {
  Cyc_st_add(data, "scheme/cxr.sld:cdaadr");

closureN_type c_73491;
c_73491.hdr.mark = gc_color_red;
 c_73491.hdr.grayed = 0;
c_73491.tag = closureN_tag;
 c_73491.fn = (function_type)__lambda_42;
c_73491.num_args = 1;
c_73491.num_elements = 1;
c_73491.elements = (object *)alloca(sizeof(object) * 1);
c_73491.elements[0] = k_7384;

return_closcall1(data,  lis_738,  &c_73491);; 
}

static void __lambda_42(void *data, int argc, object self_73226, object r_7388) {
  return_closcall1(data,  ((closureN)self_73226)->elements[0],  Cyc_cdr(data, Cyc_car(data, Cyc_car(data, Cyc_cdr(data, r_7388)))));; 
}

static void __lambda_41(void *data, int argc, closure _,object k_7391, object lis_739) {
  Cyc_st_add(data, "scheme/cxr.sld:cdaaar");

closureN_type c_73478;
c_73478.hdr.mark = gc_color_red;
 c_73478.hdr.grayed = 0;
c_73478.tag = closureN_tag;
 c_73478.fn = (function_type)__lambda_40;
c_73478.num_args = 1;
c_73478.num_elements = 1;
c_73478.elements = (object *)alloca(sizeof(object) * 1);
c_73478.elements[0] = k_7391;

return_closcall1(data,  lis_739,  &c_73478);; 
}

static void __lambda_40(void *data, int argc, object self_73227, object r_7395) {
  return_closcall1(data,  ((closureN)self_73227)->elements[0],  Cyc_cdr(data, Cyc_car(data, Cyc_car(data, Cyc_car(data, r_7395)))));; 
}

static void __lambda_39(void *data, int argc, closure _,object k_7398, object lis_7310) {
  Cyc_st_add(data, "scheme/cxr.sld:cadddr");

closureN_type c_73465;
c_73465.hdr.mark = gc_color_red;
 c_73465.hdr.grayed = 0;
c_73465.tag = closureN_tag;
 c_73465.fn = (function_type)__lambda_38;
c_73465.num_args = 1;
c_73465.num_elements = 1;
c_73465.elements = (object *)alloca(sizeof(object) * 1);
c_73465.elements[0] = k_7398;

return_closcall1(data,  lis_7310,  &c_73465);; 
}

static void __lambda_38(void *data, int argc, object self_73228, object r_73102) {
  return_closcall1(data,  ((closureN)self_73228)->elements[0],  Cyc_car(data, Cyc_cdr(data, Cyc_cdr(data, Cyc_cdr(data, r_73102)))));; 
}

static void __lambda_37(void *data, int argc, closure _,object k_73105, object lis_7311) {
  Cyc_st_add(data, "scheme/cxr.sld:caddar");

closureN_type c_73452;
c_73452.hdr.mark = gc_color_red;
 c_73452.hdr.grayed = 0;
c_73452.tag = closureN_tag;
 c_73452.fn = (function_type)__lambda_36;
c_73452.num_args = 1;
c_73452.num_elements = 1;
c_73452.elements = (object *)alloca(sizeof(object) * 1);
c_73452.elements[0] = k_73105;

return_closcall1(data,  lis_7311,  &c_73452);; 
}

static void __lambda_36(void *data, int argc, object self_73229, object r_73109) {
  return_closcall1(data,  ((closureN)self_73229)->elements[0],  Cyc_car(data, Cyc_cdr(data, Cyc_cdr(data, Cyc_car(data, r_73109)))));; 
}

static void __lambda_35(void *data, int argc, closure _,object k_73112, object lis_7312) {
  Cyc_st_add(data, "scheme/cxr.sld:cadadr");

closureN_type c_73439;
c_73439.hdr.mark = gc_color_red;
 c_73439.hdr.grayed = 0;
c_73439.tag = closureN_tag;
 c_73439.fn = (function_type)__lambda_34;
c_73439.num_args = 1;
c_73439.num_elements = 1;
c_73439.elements = (object *)alloca(sizeof(object) * 1);
c_73439.elements[0] = k_73112;

return_closcall1(data,  lis_7312,  &c_73439);; 
}

static void __lambda_34(void *data, int argc, object self_73230, object r_73116) {
  return_closcall1(data,  ((closureN)self_73230)->elements[0],  Cyc_car(data, Cyc_cdr(data, Cyc_car(data, Cyc_cdr(data, r_73116)))));; 
}

static void __lambda_33(void *data, int argc, closure _,object k_73119, object lis_7313) {
  Cyc_st_add(data, "scheme/cxr.sld:cadaar");

closureN_type c_73426;
c_73426.hdr.mark = gc_color_red;
 c_73426.hdr.grayed = 0;
c_73426.tag = closureN_tag;
 c_73426.fn = (function_type)__lambda_32;
c_73426.num_args = 1;
c_73426.num_elements = 1;
c_73426.elements = (object *)alloca(sizeof(object) * 1);
c_73426.elements[0] = k_73119;

return_closcall1(data,  lis_7313,  &c_73426);; 
}

static void __lambda_32(void *data, int argc, object self_73231, object r_73123) {
  return_closcall1(data,  ((closureN)self_73231)->elements[0],  Cyc_car(data, Cyc_cdr(data, Cyc_car(data, Cyc_car(data, r_73123)))));; 
}

static void __lambda_31(void *data, int argc, closure _,object k_73126, object lis_7314) {
  Cyc_st_add(data, "scheme/cxr.sld:caaddr");

closureN_type c_73413;
c_73413.hdr.mark = gc_color_red;
 c_73413.hdr.grayed = 0;
c_73413.tag = closureN_tag;
 c_73413.fn = (function_type)__lambda_30;
c_73413.num_args = 1;
c_73413.num_elements = 1;
c_73413.elements = (object *)alloca(sizeof(object) * 1);
c_73413.elements[0] = k_73126;

return_closcall1(data,  lis_7314,  &c_73413);; 
}

static void __lambda_30(void *data, int argc, object self_73232, object r_73130) {
  return_closcall1(data,  ((closureN)self_73232)->elements[0],  Cyc_car(data, Cyc_car(data, Cyc_cdr(data, Cyc_cdr(data, r_73130)))));; 
}

static void __lambda_29(void *data, int argc, closure _,object k_73133, object lis_7315) {
  Cyc_st_add(data, "scheme/cxr.sld:caadar");

closureN_type c_73400;
c_73400.hdr.mark = gc_color_red;
 c_73400.hdr.grayed = 0;
c_73400.tag = closureN_tag;
 c_73400.fn = (function_type)__lambda_28;
c_73400.num_args = 1;
c_73400.num_elements = 1;
c_73400.elements = (object *)alloca(sizeof(object) * 1);
c_73400.elements[0] = k_73133;

return_closcall1(data,  lis_7315,  &c_73400);; 
}

static void __lambda_28(void *data, int argc, object self_73233, object r_73137) {
  return_closcall1(data,  ((closureN)self_73233)->elements[0],  Cyc_car(data, Cyc_car(data, Cyc_cdr(data, Cyc_car(data, r_73137)))));; 
}

static void __lambda_27(void *data, int argc, closure _,object k_73140, object lis_7316) {
  Cyc_st_add(data, "scheme/cxr.sld:caaadr");

closureN_type c_73387;
c_73387.hdr.mark = gc_color_red;
 c_73387.hdr.grayed = 0;
c_73387.tag = closureN_tag;
 c_73387.fn = (function_type)__lambda_26;
c_73387.num_args = 1;
c_73387.num_elements = 1;
c_73387.elements = (object *)alloca(sizeof(object) * 1);
c_73387.elements[0] = k_73140;

return_closcall1(data,  lis_7316,  &c_73387);; 
}

static void __lambda_26(void *data, int argc, object self_73234, object r_73144) {
  return_closcall1(data,  ((closureN)self_73234)->elements[0],  Cyc_car(data, Cyc_car(data, Cyc_car(data, Cyc_cdr(data, r_73144)))));; 
}

static void __lambda_25(void *data, int argc, closure _,object k_73147, object lis_7317) {
  Cyc_st_add(data, "scheme/cxr.sld:caaaar");

closureN_type c_73374;
c_73374.hdr.mark = gc_color_red;
 c_73374.hdr.grayed = 0;
c_73374.tag = closureN_tag;
 c_73374.fn = (function_type)__lambda_24;
c_73374.num_args = 1;
c_73374.num_elements = 1;
c_73374.elements = (object *)alloca(sizeof(object) * 1);
c_73374.elements[0] = k_73147;

return_closcall1(data,  lis_7317,  &c_73374);; 
}

static void __lambda_24(void *data, int argc, object self_73235, object r_73151) {
  return_closcall1(data,  ((closureN)self_73235)->elements[0],  Cyc_car(data, Cyc_car(data, Cyc_car(data, Cyc_car(data, r_73151)))));; 
}

static void __lambda_23(void *data, int argc, closure _,object k_73154, object lis_7318) {
  Cyc_st_add(data, "scheme/cxr.sld:cdddr");

closureN_type c_73363;
c_73363.hdr.mark = gc_color_red;
 c_73363.hdr.grayed = 0;
c_73363.tag = closureN_tag;
 c_73363.fn = (function_type)__lambda_22;
c_73363.num_args = 1;
c_73363.num_elements = 1;
c_73363.elements = (object *)alloca(sizeof(object) * 1);
c_73363.elements[0] = k_73154;

return_closcall1(data,  lis_7318,  &c_73363);; 
}

static void __lambda_22(void *data, int argc, object self_73236, object r_73157) {
  return_closcall1(data,  ((closureN)self_73236)->elements[0],  Cyc_cdr(data, Cyc_cdr(data, Cyc_cdr(data, r_73157))));; 
}

static void __lambda_21(void *data, int argc, closure _,object k_73160, object lis_7319) {
  Cyc_st_add(data, "scheme/cxr.sld:cddar");

closureN_type c_73352;
c_73352.hdr.mark = gc_color_red;
 c_73352.hdr.grayed = 0;
c_73352.tag = closureN_tag;
 c_73352.fn = (function_type)__lambda_20;
c_73352.num_args = 1;
c_73352.num_elements = 1;
c_73352.elements = (object *)alloca(sizeof(object) * 1);
c_73352.elements[0] = k_73160;

return_closcall1(data,  lis_7319,  &c_73352);; 
}

static void __lambda_20(void *data, int argc, object self_73237, object r_73163) {
  return_closcall1(data,  ((closureN)self_73237)->elements[0],  Cyc_cdr(data, Cyc_cdr(data, Cyc_car(data, r_73163))));; 
}

static void __lambda_19(void *data, int argc, closure _,object k_73166, object lis_7320) {
  Cyc_st_add(data, "scheme/cxr.sld:cdadr");

closureN_type c_73341;
c_73341.hdr.mark = gc_color_red;
 c_73341.hdr.grayed = 0;
c_73341.tag = closureN_tag;
 c_73341.fn = (function_type)__lambda_18;
c_73341.num_args = 1;
c_73341.num_elements = 1;
c_73341.elements = (object *)alloca(sizeof(object) * 1);
c_73341.elements[0] = k_73166;

return_closcall1(data,  lis_7320,  &c_73341);; 
}

static void __lambda_18(void *data, int argc, object self_73238, object r_73169) {
  return_closcall1(data,  ((closureN)self_73238)->elements[0],  Cyc_cdr(data, Cyc_car(data, Cyc_cdr(data, r_73169))));; 
}

static void __lambda_17(void *data, int argc, closure _,object k_73172, object lis_7321) {
  Cyc_st_add(data, "scheme/cxr.sld:cdaar");

closureN_type c_73330;
c_73330.hdr.mark = gc_color_red;
 c_73330.hdr.grayed = 0;
c_73330.tag = closureN_tag;
 c_73330.fn = (function_type)__lambda_16;
c_73330.num_args = 1;
c_73330.num_elements = 1;
c_73330.elements = (object *)alloca(sizeof(object) * 1);
c_73330.elements[0] = k_73172;

return_closcall1(data,  lis_7321,  &c_73330);; 
}

static void __lambda_16(void *data, int argc, object self_73239, object r_73175) {
  return_closcall1(data,  ((closureN)self_73239)->elements[0],  Cyc_cdr(data, Cyc_car(data, Cyc_car(data, r_73175))));; 
}

static void __lambda_15(void *data, int argc, closure _,object k_73178, object lis_7322) {
  Cyc_st_add(data, "scheme/cxr.sld:caddr");

closureN_type c_73319;
c_73319.hdr.mark = gc_color_red;
 c_73319.hdr.grayed = 0;
c_73319.tag = closureN_tag;
 c_73319.fn = (function_type)__lambda_14;
c_73319.num_args = 1;
c_73319.num_elements = 1;
c_73319.elements = (object *)alloca(sizeof(object) * 1);
c_73319.elements[0] = k_73178;

return_closcall1(data,  lis_7322,  &c_73319);; 
}

static void __lambda_14(void *data, int argc, object self_73240, object r_73181) {
  return_closcall1(data,  ((closureN)self_73240)->elements[0],  Cyc_car(data, Cyc_cdr(data, Cyc_cdr(data, r_73181))));; 
}

static void __lambda_13(void *data, int argc, closure _,object k_73184, object lis_7323) {
  Cyc_st_add(data, "scheme/cxr.sld:cadar");

closureN_type c_73308;
c_73308.hdr.mark = gc_color_red;
 c_73308.hdr.grayed = 0;
c_73308.tag = closureN_tag;
 c_73308.fn = (function_type)__lambda_12;
c_73308.num_args = 1;
c_73308.num_elements = 1;
c_73308.elements = (object *)alloca(sizeof(object) * 1);
c_73308.elements[0] = k_73184;

return_closcall1(data,  lis_7323,  &c_73308);; 
}

static void __lambda_12(void *data, int argc, object self_73241, object r_73187) {
  return_closcall1(data,  ((closureN)self_73241)->elements[0],  Cyc_car(data, Cyc_cdr(data, Cyc_car(data, r_73187))));; 
}

static void __lambda_11(void *data, int argc, closure _,object k_73190, object lis_7324) {
  Cyc_st_add(data, "scheme/cxr.sld:caadr");

closureN_type c_73297;
c_73297.hdr.mark = gc_color_red;
 c_73297.hdr.grayed = 0;
c_73297.tag = closureN_tag;
 c_73297.fn = (function_type)__lambda_10;
c_73297.num_args = 1;
c_73297.num_elements = 1;
c_73297.elements = (object *)alloca(sizeof(object) * 1);
c_73297.elements[0] = k_73190;

return_closcall1(data,  lis_7324,  &c_73297);; 
}

static void __lambda_10(void *data, int argc, object self_73242, object r_73193) {
  return_closcall1(data,  ((closureN)self_73242)->elements[0],  Cyc_car(data, Cyc_car(data, Cyc_cdr(data, r_73193))));; 
}

static void __lambda_9(void *data, int argc, closure _,object k_73196, object lis_7325) {
  Cyc_st_add(data, "scheme/cxr.sld:caaar");

closureN_type c_73286;
c_73286.hdr.mark = gc_color_red;
 c_73286.hdr.grayed = 0;
c_73286.tag = closureN_tag;
 c_73286.fn = (function_type)__lambda_8;
c_73286.num_args = 1;
c_73286.num_elements = 1;
c_73286.elements = (object *)alloca(sizeof(object) * 1);
c_73286.elements[0] = k_73196;

return_closcall1(data,  lis_7325,  &c_73286);; 
}

static void __lambda_8(void *data, int argc, object self_73243, object r_73199) {
  return_closcall1(data,  ((closureN)self_73243)->elements[0],  Cyc_car(data, Cyc_car(data, Cyc_car(data, r_73199))));; 
}

static void __lambda_7(void *data, int argc, closure _,object k_73202, object lis_7326) {
  Cyc_st_add(data, "scheme/cxr.sld:cddr");

closureN_type c_73277;
c_73277.hdr.mark = gc_color_red;
 c_73277.hdr.grayed = 0;
c_73277.tag = closureN_tag;
 c_73277.fn = (function_type)__lambda_6;
c_73277.num_args = 1;
c_73277.num_elements = 1;
c_73277.elements = (object *)alloca(sizeof(object) * 1);
c_73277.elements[0] = k_73202;

return_closcall1(data,  lis_7326,  &c_73277);; 
}

static void __lambda_6(void *data, int argc, object self_73244, object r_73204) {
  return_closcall1(data,  ((closureN)self_73244)->elements[0],  Cyc_cdr(data, Cyc_cdr(data, r_73204)));; 
}

static void __lambda_5(void *data, int argc, closure _,object k_73207, object lis_7327) {
  Cyc_st_add(data, "scheme/cxr.sld:cdar");

closureN_type c_73268;
c_73268.hdr.mark = gc_color_red;
 c_73268.hdr.grayed = 0;
c_73268.tag = closureN_tag;
 c_73268.fn = (function_type)__lambda_4;
c_73268.num_args = 1;
c_73268.num_elements = 1;
c_73268.elements = (object *)alloca(sizeof(object) * 1);
c_73268.elements[0] = k_73207;

return_closcall1(data,  lis_7327,  &c_73268);; 
}

static void __lambda_4(void *data, int argc, object self_73245, object r_73209) {
  return_closcall1(data,  ((closureN)self_73245)->elements[0],  Cyc_cdr(data, Cyc_car(data, r_73209)));; 
}

static void __lambda_3(void *data, int argc, closure _,object k_73212, object lis_7328) {
  Cyc_st_add(data, "scheme/cxr.sld:cadr");

closureN_type c_73259;
c_73259.hdr.mark = gc_color_red;
 c_73259.hdr.grayed = 0;
c_73259.tag = closureN_tag;
 c_73259.fn = (function_type)__lambda_2;
c_73259.num_args = 1;
c_73259.num_elements = 1;
c_73259.elements = (object *)alloca(sizeof(object) * 1);
c_73259.elements[0] = k_73212;

return_closcall1(data,  lis_7328,  &c_73259);; 
}

static void __lambda_2(void *data, int argc, object self_73246, object r_73214) {
  return_closcall1(data,  ((closureN)self_73246)->elements[0],  Cyc_car(data, Cyc_cdr(data, r_73214)));; 
}

static void __lambda_1(void *data, int argc, closure _,object k_73217, object lis_7329) {
  Cyc_st_add(data, "scheme/cxr.sld:caar");

closureN_type c_73250;
c_73250.hdr.mark = gc_color_red;
 c_73250.hdr.grayed = 0;
c_73250.tag = closureN_tag;
 c_73250.fn = (function_type)__lambda_0;
c_73250.num_args = 1;
c_73250.num_elements = 1;
c_73250.elements = (object *)alloca(sizeof(object) * 1);
c_73250.elements[0] = k_73217;

return_closcall1(data,  lis_7329,  &c_73250);; 
}

static void __lambda_0(void *data, int argc, object self_73247, object r_73219) {
  return_closcall1(data,  ((closureN)self_73247)->elements[0],  Cyc_car(data, Cyc_car(data, r_73219)));; 
}

void c_schemecxr_entry_pt(data, argc, cont,value) void *data; int argc; closure cont; object value;{ 

  add_global((object *) &__glo_lib_91init_117schemecxr_scheme_cxr);
  add_global((object *) &__glo_caaaaar_scheme_cxr);
  add_global((object *) &__glo_cddddr_scheme_cxr);
  add_global((object *) &__glo_cdddar_scheme_cxr);
  add_global((object *) &__glo_cddadr_scheme_cxr);
  add_global((object *) &__glo_cddaar_scheme_cxr);
  add_global((object *) &__glo_cdaddr_scheme_cxr);
  add_global((object *) &__glo_cdadar_scheme_cxr);
  add_global((object *) &__glo_cdaadr_scheme_cxr);
  add_global((object *) &__glo_cdaaar_scheme_cxr);
  add_global((object *) &__glo_cadddr_scheme_cxr);
  add_global((object *) &__glo_caddar_scheme_cxr);
  add_global((object *) &__glo_cadadr_scheme_cxr);
  add_global((object *) &__glo_cadaar_scheme_cxr);
  add_global((object *) &__glo_caaddr_scheme_cxr);
  add_global((object *) &__glo_caadar_scheme_cxr);
  add_global((object *) &__glo_caaadr_scheme_cxr);
  add_global((object *) &__glo_caaaar_scheme_cxr);
  add_global((object *) &__glo_cdddr_scheme_cxr);
  add_global((object *) &__glo_cddar_scheme_cxr);
  add_global((object *) &__glo_cdadr_scheme_cxr);
  add_global((object *) &__glo_cdaar_scheme_cxr);
  add_global((object *) &__glo_caddr_scheme_cxr);
  add_global((object *) &__glo_cadar_scheme_cxr);
  add_global((object *) &__glo_caadr_scheme_cxr);
  add_global((object *) &__glo_caaar_scheme_cxr);
  add_global((object *) &__glo_cddr_scheme_cxr);
  add_global((object *) &__glo_cdar_scheme_cxr);
  add_global((object *) &__glo_cadr_scheme_cxr);
  add_global((object *) &__glo_caar_scheme_cxr);
  mclosure0(c_73592, (function_type)__lambda_57);c_73592.num_args = 0; 
  __glo_lib_91init_117schemecxr_scheme_cxr = &c_73592; 
  mclosure0(c_73580, (function_type)__lambda_56);c_73580.num_args = 1; 
  __glo_caaaaar_scheme_cxr = &c_73580; 
  mclosure0(c_73567, (function_type)__lambda_55);c_73567.num_args = 1; 
  __glo_cddddr_scheme_cxr = &c_73567; 
  mclosure0(c_73554, (function_type)__lambda_53);c_73554.num_args = 1; 
  __glo_cdddar_scheme_cxr = &c_73554; 
  mclosure0(c_73541, (function_type)__lambda_51);c_73541.num_args = 1; 
  __glo_cddadr_scheme_cxr = &c_73541; 
  mclosure0(c_73528, (function_type)__lambda_49);c_73528.num_args = 1; 
  __glo_cddaar_scheme_cxr = &c_73528; 
  mclosure0(c_73515, (function_type)__lambda_47);c_73515.num_args = 1; 
  __glo_cdaddr_scheme_cxr = &c_73515; 
  mclosure0(c_73502, (function_type)__lambda_45);c_73502.num_args = 1; 
  __glo_cdadar_scheme_cxr = &c_73502; 
  mclosure0(c_73489, (function_type)__lambda_43);c_73489.num_args = 1; 
  __glo_cdaadr_scheme_cxr = &c_73489; 
  mclosure0(c_73476, (function_type)__lambda_41);c_73476.num_args = 1; 
  __glo_cdaaar_scheme_cxr = &c_73476; 
  mclosure0(c_73463, (function_type)__lambda_39);c_73463.num_args = 1; 
  __glo_cadddr_scheme_cxr = &c_73463; 
  mclosure0(c_73450, (function_type)__lambda_37);c_73450.num_args = 1; 
  __glo_caddar_scheme_cxr = &c_73450; 
  mclosure0(c_73437, (function_type)__lambda_35);c_73437.num_args = 1; 
  __glo_cadadr_scheme_cxr = &c_73437; 
  mclosure0(c_73424, (function_type)__lambda_33);c_73424.num_args = 1; 
  __glo_cadaar_scheme_cxr = &c_73424; 
  mclosure0(c_73411, (function_type)__lambda_31);c_73411.num_args = 1; 
  __glo_caaddr_scheme_cxr = &c_73411; 
  mclosure0(c_73398, (function_type)__lambda_29);c_73398.num_args = 1; 
  __glo_caadar_scheme_cxr = &c_73398; 
  mclosure0(c_73385, (function_type)__lambda_27);c_73385.num_args = 1; 
  __glo_caaadr_scheme_cxr = &c_73385; 
  mclosure0(c_73372, (function_type)__lambda_25);c_73372.num_args = 1; 
  __glo_caaaar_scheme_cxr = &c_73372; 
  mclosure0(c_73361, (function_type)__lambda_23);c_73361.num_args = 1; 
  __glo_cdddr_scheme_cxr = &c_73361; 
  mclosure0(c_73350, (function_type)__lambda_21);c_73350.num_args = 1; 
  __glo_cddar_scheme_cxr = &c_73350; 
  mclosure0(c_73339, (function_type)__lambda_19);c_73339.num_args = 1; 
  __glo_cdadr_scheme_cxr = &c_73339; 
  mclosure0(c_73328, (function_type)__lambda_17);c_73328.num_args = 1; 
  __glo_cdaar_scheme_cxr = &c_73328; 
  mclosure0(c_73317, (function_type)__lambda_15);c_73317.num_args = 1; 
  __glo_caddr_scheme_cxr = &c_73317; 
  mclosure0(c_73306, (function_type)__lambda_13);c_73306.num_args = 1; 
  __glo_cadar_scheme_cxr = &c_73306; 
  mclosure0(c_73295, (function_type)__lambda_11);c_73295.num_args = 1; 
  __glo_caadr_scheme_cxr = &c_73295; 
  mclosure0(c_73284, (function_type)__lambda_9);c_73284.num_args = 1; 
  __glo_caaar_scheme_cxr = &c_73284; 
  mclosure0(c_73275, (function_type)__lambda_7);c_73275.num_args = 1; 
  __glo_cddr_scheme_cxr = &c_73275; 
  mclosure0(c_73266, (function_type)__lambda_5);c_73266.num_args = 1; 
  __glo_cdar_scheme_cxr = &c_73266; 
  mclosure0(c_73257, (function_type)__lambda_3);c_73257.num_args = 1; 
  __glo_cadr_scheme_cxr = &c_73257; 
  mclosure0(c_73248, (function_type)__lambda_1);c_73248.num_args = 1; 
  __glo_caar_scheme_cxr = &c_73248; 

  make_cvar(cvar_73594, (object *)&__glo_lib_91init_117schemecxr_scheme_cxr);make_pair(pair_73595, find_or_add_symbol("lib-init:schemecxr"), &cvar_73594);
  make_cvar(cvar_73596, (object *)&__glo_caaaaar_scheme_cxr);make_pair(pair_73597, find_or_add_symbol("caaaaar"), &cvar_73596);
  make_cvar(cvar_73598, (object *)&__glo_cddddr_scheme_cxr);make_pair(pair_73599, find_or_add_symbol("cddddr"), &cvar_73598);
  make_cvar(cvar_73600, (object *)&__glo_cdddar_scheme_cxr);make_pair(pair_73601, find_or_add_symbol("cdddar"), &cvar_73600);
  make_cvar(cvar_73602, (object *)&__glo_cddadr_scheme_cxr);make_pair(pair_73603, find_or_add_symbol("cddadr"), &cvar_73602);
  make_cvar(cvar_73604, (object *)&__glo_cddaar_scheme_cxr);make_pair(pair_73605, find_or_add_symbol("cddaar"), &cvar_73604);
  make_cvar(cvar_73606, (object *)&__glo_cdaddr_scheme_cxr);make_pair(pair_73607, find_or_add_symbol("cdaddr"), &cvar_73606);
  make_cvar(cvar_73608, (object *)&__glo_cdadar_scheme_cxr);make_pair(pair_73609, find_or_add_symbol("cdadar"), &cvar_73608);
  make_cvar(cvar_73610, (object *)&__glo_cdaadr_scheme_cxr);make_pair(pair_73611, find_or_add_symbol("cdaadr"), &cvar_73610);
  make_cvar(cvar_73612, (object *)&__glo_cdaaar_scheme_cxr);make_pair(pair_73613, find_or_add_symbol("cdaaar"), &cvar_73612);
  make_cvar(cvar_73614, (object *)&__glo_cadddr_scheme_cxr);make_pair(pair_73615, find_or_add_symbol("cadddr"), &cvar_73614);
  make_cvar(cvar_73616, (object *)&__glo_caddar_scheme_cxr);make_pair(pair_73617, find_or_add_symbol("caddar"), &cvar_73616);
  make_cvar(cvar_73618, (object *)&__glo_cadadr_scheme_cxr);make_pair(pair_73619, find_or_add_symbol("cadadr"), &cvar_73618);
  make_cvar(cvar_73620, (object *)&__glo_cadaar_scheme_cxr);make_pair(pair_73621, find_or_add_symbol("cadaar"), &cvar_73620);
  make_cvar(cvar_73622, (object *)&__glo_caaddr_scheme_cxr);make_pair(pair_73623, find_or_add_symbol("caaddr"), &cvar_73622);
  make_cvar(cvar_73624, (object *)&__glo_caadar_scheme_cxr);make_pair(pair_73625, find_or_add_symbol("caadar"), &cvar_73624);
  make_cvar(cvar_73626, (object *)&__glo_caaadr_scheme_cxr);make_pair(pair_73627, find_or_add_symbol("caaadr"), &cvar_73626);
  make_cvar(cvar_73628, (object *)&__glo_caaaar_scheme_cxr);make_pair(pair_73629, find_or_add_symbol("caaaar"), &cvar_73628);
  make_cvar(cvar_73630, (object *)&__glo_cdddr_scheme_cxr);make_pair(pair_73631, find_or_add_symbol("cdddr"), &cvar_73630);
  make_cvar(cvar_73632, (object *)&__glo_cddar_scheme_cxr);make_pair(pair_73633, find_or_add_symbol("cddar"), &cvar_73632);
  make_cvar(cvar_73634, (object *)&__glo_cdadr_scheme_cxr);make_pair(pair_73635, find_or_add_symbol("cdadr"), &cvar_73634);
  make_cvar(cvar_73636, (object *)&__glo_cdaar_scheme_cxr);make_pair(pair_73637, find_or_add_symbol("cdaar"), &cvar_73636);
  make_cvar(cvar_73638, (object *)&__glo_caddr_scheme_cxr);make_pair(pair_73639, find_or_add_symbol("caddr"), &cvar_73638);
  make_cvar(cvar_73640, (object *)&__glo_cadar_scheme_cxr);make_pair(pair_73641, find_or_add_symbol("cadar"), &cvar_73640);
  make_cvar(cvar_73642, (object *)&__glo_caadr_scheme_cxr);make_pair(pair_73643, find_or_add_symbol("caadr"), &cvar_73642);
  make_cvar(cvar_73644, (object *)&__glo_caaar_scheme_cxr);make_pair(pair_73645, find_or_add_symbol("caaar"), &cvar_73644);
  make_cvar(cvar_73646, (object *)&__glo_cddr_scheme_cxr);make_pair(pair_73647, find_or_add_symbol("cddr"), &cvar_73646);
  make_cvar(cvar_73648, (object *)&__glo_cdar_scheme_cxr);make_pair(pair_73649, find_or_add_symbol("cdar"), &cvar_73648);
  make_cvar(cvar_73650, (object *)&__glo_cadr_scheme_cxr);make_pair(pair_73651, find_or_add_symbol("cadr"), &cvar_73650);
  make_cvar(cvar_73652, (object *)&__glo_caar_scheme_cxr);make_pair(pair_73653, find_or_add_symbol("caar"), &cvar_73652);
make_pair(c_73654, &pair_73595,Cyc_global_variables);
make_pair(c_73655, &pair_73597, &c_73654);
make_pair(c_73656, &pair_73599, &c_73655);
make_pair(c_73657, &pair_73601, &c_73656);
make_pair(c_73658, &pair_73603, &c_73657);
make_pair(c_73659, &pair_73605, &c_73658);
make_pair(c_73660, &pair_73607, &c_73659);
make_pair(c_73661, &pair_73609, &c_73660);
make_pair(c_73662, &pair_73611, &c_73661);
make_pair(c_73663, &pair_73613, &c_73662);
make_pair(c_73664, &pair_73615, &c_73663);
make_pair(c_73665, &pair_73617, &c_73664);
make_pair(c_73666, &pair_73619, &c_73665);
make_pair(c_73667, &pair_73621, &c_73666);
make_pair(c_73668, &pair_73623, &c_73667);
make_pair(c_73669, &pair_73625, &c_73668);
make_pair(c_73670, &pair_73627, &c_73669);
make_pair(c_73671, &pair_73629, &c_73670);
make_pair(c_73672, &pair_73631, &c_73671);
make_pair(c_73673, &pair_73633, &c_73672);
make_pair(c_73674, &pair_73635, &c_73673);
make_pair(c_73675, &pair_73637, &c_73674);
make_pair(c_73676, &pair_73639, &c_73675);
make_pair(c_73677, &pair_73641, &c_73676);
make_pair(c_73678, &pair_73643, &c_73677);
make_pair(c_73679, &pair_73645, &c_73678);
make_pair(c_73680, &pair_73647, &c_73679);
make_pair(c_73681, &pair_73649, &c_73680);
make_pair(c_73682, &pair_73651, &c_73681);
make_pair(c_73683, &pair_73653, &c_73682);
Cyc_global_variables = &c_73683;
cont = ((closure1_type *)cont)->element;
(((closure)__glo_lib_91init_117schemecxr_scheme_cxr)->fn)(data, 1, cont, cont);
}
