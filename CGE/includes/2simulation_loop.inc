*----------------------------------------------------------------------
*4. Time period loop
*----------------------------------------------------------------------

$include includes\2initialize.inc

 TAPSX(X,T) = 0;

LOOP(XC,

$include includes\2varinit.inc

  LOOP(TC,
    IF(NOT T1(TC),

*     Long term TFP growth
      alphava(A,RD) = alphava(A,RD) * (1+TFPGR(A,RD,XC,TC));

*     Long term factor-specific productivity growth
      fprd(F,A,RD)$(NOT AFX(A,RD)) = fprd(F,A,RD) * (1+FPRDGR(F,XC,TC));

*     World price changes
*      pwebar(C,RW) = pwebar(C,RW) * (1+PWEGR(C,XC,TC));
      PWE.L(C,RW)  = PWE.L(C,RW)  * (1+PWEGR(C,XC,TC));
      PWM.L(C,RW)  = PWM.L(C,RW)  * (1+PWMGR(C,XC,TC));

*     Population growth
      hpop(H) = hpop(H) * (1+POPGR(H,XC,TC));

*     Exgenous transfer changes
      trnsfr(INS,ACNT) = trnsfr(INS,ACNT) * (1+TRNSFRGR(INS,ACNT,XC,TC));

*     Capital stock accumulation and allocation
$include includes\2capital.inc

*     Labor supply growth
      QF.L(FLAB,A,RD)$(NOT T1(TC)) = QF.L(FLAB,A,RD)*(1+FACGR(FLAB,XC,TC));
      QF.L('FEGY',A,RD)$(NOT T1(TC)) = QF.L('FEGY',A,RD)*(1+FACGR('FEGY',XC,TC));
      QF.L('FLND',A,RD)$(NOT T1(TC)) = QF.L('FLND',A,RD)*(1+FACGR('FLND',XC,TC));

*     Total factor supply
      QFS.L(F) = SUM((RD,A), QF.L(F,A,RD));

    );

$include includes\2closures.inc

 STANDCGE.SOLVELINK = 2;
 SOLVE standcge USING MCP ;

$include includes\2results.inc

  );
);
