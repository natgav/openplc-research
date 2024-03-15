#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM WAVE_GENERATOR
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,OSCILATOR)
  __DECLARE_VAR(BOOL,COUNT_UP)
  __DECLARE_VAR(BOOL,COUNT_DOWN)
  __DECLARE_VAR(UINT,OUTPUT)
  TON TON0;
  TOF TOF0;
  CTUD_UDINT CTUD_UDINT0;
  __DECLARE_VAR(BOOL,_TMP_EQ9_OUT)
  __DECLARE_VAR(BOOL,_TMP_EQ14_OUT)
  R_TRIG R_TRIG1;
  R_TRIG R_TRIG2;
  __DECLARE_VAR(UINT,_TMP_UDINT_TO_UINT29_OUT)

} WAVE_GENERATOR;

void WAVE_GENERATOR_init__(WAVE_GENERATOR *data__, BOOL retain);
// Code part
void WAVE_GENERATOR_body__(WAVE_GENERATOR *data__);
#endif //__POUS_H
