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
// PROGRAM TRAFIC_LIGHT
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  TOF TOF0;
  __DECLARE_VAR(BOOL,ALWAYS_TRUE)
  __DECLARE_VAR(BOOL,DELAY_PLC_START_UP)
  TOF TOF1;
  TOF TOF2;
  __DECLARE_VAR(BOOL,O_LEDRED)
  __DECLARE_VAR(BOOL,O_LEDORANGE)
  __DECLARE_VAR(BOOL,O_LEDGREEN)
  __DECLARE_VAR(BOOL,NO_LAMPS_ACTIVE_FOR_1S)
  F_TRIG F_TRIG0;
  F_TRIG F_TRIG1;
  F_TRIG F_TRIG2;
  TON TON0;
  SR SR0;
  TOF TOF3;
  TOF TOF4;
  TOF TOF5;
  __DECLARE_VAR(BOOL,_TMP_OR22_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND29_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND33_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND34_OUT)
  __DECLARE_VAR(BOOL,_TMP_OR13_OUT)
  __DECLARE_VAR(BOOL,_TMP_NOT14_OUT)

} TRAFIC_LIGHT;

void TRAFIC_LIGHT_init__(TRAFIC_LIGHT *data__, BOOL retain);
// Code part
void TRAFIC_LIGHT_body__(TRAFIC_LIGHT *data__);
#endif //__POUS_H
