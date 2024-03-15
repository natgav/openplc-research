#include "POUS.h"
void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void WAVE_GENERATOR_init__(WAVE_GENERATOR *data__, BOOL retain) {
  __INIT_VAR(data__->OSCILATOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->COUNT_UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->COUNT_DOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUTPUT,0,retain)
  TON_init__(&data__->TON0,retain);
  TOF_init__(&data__->TOF0,retain);
  CTUD_UDINT_init__(&data__->CTUD_UDINT0,retain);
  __INIT_VAR(data__->_TMP_EQ9_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ14_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  __INIT_VAR(data__->_TMP_UDINT_TO_UINT29_OUT,0,retain)
}

// Code part
void WAVE_GENERATOR_body__(WAVE_GENERATOR *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TON0.,IN,,!(__GET_VAR(data__->OSCILATOR,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 100, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 100, 0, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,OSCILATOR,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->,_TMP_EQ9_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->OUTPUT,),
    (UINT)0));
  if (__GET_VAR(data__->_TMP_EQ9_OUT,)) {
    __SET_VAR(data__->,COUNT_UP,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->_TMP_EQ9_OUT,)) {
    __SET_VAR(data__->,COUNT_DOWN,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,_TMP_EQ14_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->OUTPUT,),
    (UINT)100));
  if (__GET_VAR(data__->_TMP_EQ14_OUT,)) {
    __SET_VAR(data__->,COUNT_DOWN,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->_TMP_EQ14_OUT,)) {
    __SET_VAR(data__->,COUNT_UP,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG1.,CLK,,(__GET_VAR(data__->COUNT_UP,) && __GET_VAR(data__->OSCILATOR,)));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->R_TRIG2.,CLK,,(__GET_VAR(data__->COUNT_DOWN,) && __GET_VAR(data__->OSCILATOR,)));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTUD_UDINT0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTUD_UDINT0.,CD,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTUD_UDINT0.,PV,,65536);
  CTUD_UDINT_body__(&data__->CTUD_UDINT0);
  __SET_VAR(data__->,_TMP_UDINT_TO_UINT29_OUT,,UDINT_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->CTUD_UDINT0.CV,)));
  __SET_VAR(data__->,OUTPUT,,__GET_VAR(data__->_TMP_UDINT_TO_UINT29_OUT,));

  goto __end;

__end:
  return;
} // WAVE_GENERATOR_body__() 





