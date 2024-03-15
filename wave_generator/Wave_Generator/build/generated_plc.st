PROGRAM wave_generator
  VAR
    oscilator : BOOL;
    count_up : BOOL;
    count_down : BOOL;
  END_VAR
  VAR
    output AT %QW0 : UINT;
  END_VAR
  VAR
    TON0 : TON;
    TOF0 : TOF;
    CTUD_UDINT0 : CTUD_UDINT;
    _TMP_EQ9_OUT : BOOL;
    _TMP_EQ14_OUT : BOOL;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    _TMP_UDINT_TO_UINT29_OUT : UINT;
  END_VAR

  TON0(IN := NOT(oscilator), PT := T#100ms);
  TOF0(IN := TON0.Q, PT := T#100ms);
  oscilator := TOF0.Q;
  _TMP_EQ9_OUT := EQ(output, 0);
  IF _TMP_EQ9_OUT THEN
    count_up := TRUE; (*set*)
  END_IF;
  IF _TMP_EQ9_OUT THEN
    count_down := FALSE; (*reset*)
  END_IF;
  _TMP_EQ14_OUT := EQ(output, 100);
  IF _TMP_EQ14_OUT THEN
    count_down := TRUE; (*set*)
  END_IF;
  IF _TMP_EQ14_OUT THEN
    count_up := FALSE; (*reset*)
  END_IF;
  R_TRIG1(CLK := count_up AND oscilator);
  R_TRIG2(CLK := count_down AND oscilator);
  CTUD_UDINT0(CU := R_TRIG1.Q, CD := R_TRIG2.Q, PV := 65536);
  _TMP_UDINT_TO_UINT29_OUT := UDINT_TO_UINT(CTUD_UDINT0.CV);
  output := _TMP_UDINT_TO_UINT29_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : wave_generator;
  END_RESOURCE
END_CONFIGURATION
