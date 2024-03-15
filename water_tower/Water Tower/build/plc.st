TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    ADD10_OUT : UINT;
    EQ13_OUT : BOOL;
    SEL15_OUT : UINT;
    AND7_OUT : BOOL;
  END_VAR

  ADD10_OUT := ADD(COUNTER, 1);
  EQ13_OUT := EQ(N, ADD10_OUT);
  SEL15_OUT := SEL(EQ13_OUT, ADD10_OUT, 0);
  COUNTER := SEL15_OUT;
  AND7_OUT := AND(EQ13_OUT, TRIG);
  py_eval(TRIG := AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


FUNCTION_BLOCK Level_Filtering
  VAR_INPUT
    raw_level : INT;
  END_VAR
  VAR
    level_real : REAL;
    avg : LREAL;
    level_array : ARRAY [1..20] OF REAL;
    i : INT;
    current_array_pos : INT := 1;
  END_VAR
  VAR_OUTPUT
    filtered_level : INT;
  END_VAR

  (* Level Conversion *)
  level_real := INT_TO_REAL(raw_level);
  level_real := level_real - 107.0;
  level_real := level_real * 0.483091;
  level_real := level_real * 100.0;

  (* Store value in average array *)
  level_array[current_array_pos] := level_real;
  current_array_pos := current_array_pos + 1;

  (* Prevent array_pos overflow *)
  if current_array_pos > 20 then
    current_array_pos := 1;
  end_if;

  (* Calculate average *)
  avg := 0.0;
  i := 1;
  while (i < 21) do
    avg := avg + REAL_TO_LREAL(level_array[i]);
    i := i + 1;
  end_while;
  avg := avg / 20.0;

  (* Set output value *)
  filtered_level := LREAL_TO_INT(avg);
END_FUNCTION_BLOCK

PROGRAM My_Program
  VAR
    Level : INT;
    Level_filtered : INT;
    min_sp : INT;
    max_sp : INT;
    mode_register : INT;
    pump_register : INT;
    valve_register : INT;
    pump : BOOL;
    valve : BOOL;
    pump_man : BOOL;
    pump_auto : BOOL;
  END_VAR
  VAR
    Level_Filtering0 : Level_Filtering;
    LE98_OUT : BOOL;
    GE103_OUT : BOOL;
    EQ104_OUT : BOOL;
    EQ33_OUT : BOOL;
    EQ49_OUT : BOOL;
    EQ38_OUT : BOOL;
  END_VAR

  Level_Filtering0(raw_level := Level);
  Level_filtered := Level_Filtering0.filtered_level;
  LE98_OUT := LE(Level_filtered, min_sp);
  IF LE98_OUT THEN
    pump_auto := TRUE; (*set*)
  END_IF;
  GE103_OUT := GE(Level_filtered, max_sp);
  IF GE103_OUT THEN
    pump_auto := FALSE; (*reset*)
  END_IF;
  EQ104_OUT := EQ(pump_register, 1);
  pump_man := EQ104_OUT;
  EQ33_OUT := EQ(valve_register, 1);
  valve := EQ33_OUT;
  EQ49_OUT := EQ(mode_register, 1);
  EQ38_OUT := EQ(mode_register, 2);
  pump := pump_auto AND EQ38_OUT OR pump_man AND EQ49_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : My_Program;
  END_RESOURCE
END_CONFIGURATION
