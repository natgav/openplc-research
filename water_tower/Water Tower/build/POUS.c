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





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void LEVEL_FILTERING_init__(LEVEL_FILTERING *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RAW_LEVEL,0,retain)
  __INIT_VAR(data__->LEVEL_REAL,0,retain)
  __INIT_VAR(data__->AVG,0,retain)
  {
    static const __ARRAY_OF_REAL_20 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,LEVEL_ARRAY,,temp);
  }
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->CURRENT_ARRAY_POS,1,retain)
  __INIT_VAR(data__->FILTERED_LEVEL,0,retain)
}

// Code part
void LEVEL_FILTERING_body__(LEVEL_FILTERING *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,LEVEL_REAL,,INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->RAW_LEVEL,)));
  __SET_VAR(data__->,LEVEL_REAL,,(__GET_VAR(data__->LEVEL_REAL,) - 107.0));
  __SET_VAR(data__->,LEVEL_REAL,,(__GET_VAR(data__->LEVEL_REAL,) * 0.483091));
  __SET_VAR(data__->,LEVEL_REAL,,(__GET_VAR(data__->LEVEL_REAL,) * 100.0));
  __SET_VAR(data__->,LEVEL_ARRAY,.table[(__GET_VAR(data__->CURRENT_ARRAY_POS,)) - (1)],__GET_VAR(data__->LEVEL_REAL,));
  __SET_VAR(data__->,CURRENT_ARRAY_POS,,(__GET_VAR(data__->CURRENT_ARRAY_POS,) + 1));
  if ((__GET_VAR(data__->CURRENT_ARRAY_POS,) > 20)) {
    __SET_VAR(data__->,CURRENT_ARRAY_POS,,1);
  };
  __SET_VAR(data__->,AVG,,0.0);
  __SET_VAR(data__->,I,,1);
  while ((__GET_VAR(data__->I,) < 21)) {
    __SET_VAR(data__->,AVG,,(__GET_VAR(data__->AVG,) + REAL_TO_LREAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->LEVEL_ARRAY,.table[(__GET_VAR(data__->I,)) - (1)]))));
    __SET_VAR(data__->,I,,(__GET_VAR(data__->I,) + 1));
  };
  __SET_VAR(data__->,AVG,,(__GET_VAR(data__->AVG,) / 20.0));
  __SET_VAR(data__->,FILTERED_LEVEL,,LREAL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (LREAL)__GET_VAR(data__->AVG,)));

  goto __end;

__end:
  return;
} // LEVEL_FILTERING_body__() 





void MY_PROGRAM_init__(MY_PROGRAM *data__, BOOL retain) {
  __INIT_VAR(data__->LEVEL,0,retain)
  __INIT_VAR(data__->LEVEL_FILTERED,0,retain)
  __INIT_VAR(data__->MIN_SP,0,retain)
  __INIT_VAR(data__->MAX_SP,0,retain)
  __INIT_VAR(data__->MODE_REGISTER,0,retain)
  __INIT_VAR(data__->PUMP_REGISTER,0,retain)
  __INIT_VAR(data__->VALVE_REGISTER,0,retain)
  __INIT_VAR(data__->PUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUMP_MAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUMP_AUTO,__BOOL_LITERAL(FALSE),retain)
  LEVEL_FILTERING_init__(&data__->LEVEL_FILTERING0,retain);
  __INIT_VAR(data__->LE98_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GE103_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EQ104_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EQ33_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EQ49_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EQ38_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void MY_PROGRAM_body__(MY_PROGRAM *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->LEVEL_FILTERING0.,RAW_LEVEL,,__GET_VAR(data__->LEVEL,));
  LEVEL_FILTERING_body__(&data__->LEVEL_FILTERING0);
  __SET_VAR(data__->,LEVEL_FILTERED,,__GET_VAR(data__->LEVEL_FILTERING0.FILTERED_LEVEL,));
  __SET_VAR(data__->,LE98_OUT,,LE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->LEVEL_FILTERED,),
    (INT)__GET_VAR(data__->MIN_SP,)));
  if (__GET_VAR(data__->LE98_OUT,)) {
    __SET_VAR(data__->,PUMP_AUTO,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,GE103_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->LEVEL_FILTERED,),
    (INT)__GET_VAR(data__->MAX_SP,)));
  if (__GET_VAR(data__->GE103_OUT,)) {
    __SET_VAR(data__->,PUMP_AUTO,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,EQ104_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->PUMP_REGISTER,),
    (INT)1));
  __SET_VAR(data__->,PUMP_MAN,,__GET_VAR(data__->EQ104_OUT,));
  __SET_VAR(data__->,EQ33_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->VALVE_REGISTER,),
    (INT)1));
  __SET_VAR(data__->,VALVE,,__GET_VAR(data__->EQ33_OUT,));
  __SET_VAR(data__->,EQ49_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->MODE_REGISTER,),
    (INT)1));
  __SET_VAR(data__->,EQ38_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->MODE_REGISTER,),
    (INT)2));
  __SET_VAR(data__->,PUMP,,((__GET_VAR(data__->PUMP_AUTO,) && __GET_VAR(data__->EQ38_OUT,)) || (__GET_VAR(data__->PUMP_MAN,) && __GET_VAR(data__->EQ49_OUT,))));

  goto __end;

__end:
  return;
} // MY_PROGRAM_body__() 





