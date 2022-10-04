

* EBCHECK - to compare the energy use by eMOD sectors

EBCHECK('eMOD',FS,'IN',C,TC,TT,RUN) = FLOW_IN_FSFuels(FS,C,TC)*(-1);
EBCHECK('eMOD',FS,'OUT',C,TC,TT,RUN) = FLOW_OUT_FSFuels(FS,C,TC);
EBCHECK('eMOD','elec','OUT','celec',TC,TT,RUN) = ELC_FLOW(RUN,TC);

EBCHECK('eMOD','imp','OUT',C,TC,TT,RUN) = EBCHECK('eMOD','imp','OUT',C,TC,TT,RUN)+EBCHECK('eMOD','exp','IN',C,TC,TT,RUN);
EBCHECK('eMOD','exp','IN',C,TC,TT,RUN) = 0;

EBCHECK('eGEM',FS,'IN',C,TC,TT,RUN)$energy(C) = SUM(A$MFSA(FS,A),QINTX(C,A,XC,TC,TT))*(-1);
*EBCHECK('eGEM','petr','IN',C,TC,TT,RUN)$UCONV_C_T2C(C) = QINTX(C,'apetr',XC,TC,TT)/UCONV_C_T2C(C)*-1;
*EBCHECK('eGEM','exp','IN',C,TC,TT,RUN) = QEX(C,'rest',XC,TC,TT)*(-1);

EBCHECK('eGEM',FS,'OUT',C,TC,TT,RUN)$energy(C) = SUM(A$MFSA(FS,A),QXACX(A,C,XC,TC,TT));
*EBCHECK('eGEM','petr','IN',C,TC,TT,RUN)$UCONV_C_T2C(C) = QINTX(C,'apetr',XC,TC,TT)/UCONV_C_T2C(C)*-1;
EBCHECK('eGEM','imp','OUT',C,TC,TT,RUN) = QMX(C,'rest',XC,TC,TT)-QEX(C,'rest',XC,TC,TT);

EBCHECK('eMOD',FH,'IN',C,TC,TT,RUN) = FLOW_IN_FSFuels(FH,C,TC)*(-1);
EBCHECK('eGEM',FH,'IN',C,TC,TT,RUN)$energy(C) = SUM(H$MFHHT(H,FH),QHX(C,H,XC,TC,TT))*(-1);




*EBCHECK(MOD,FSeMOD,'CO2',C,TC,TT,RUN) = EBCHECK(MOD,FSeMOD,'IN',C,TC,TT,RUN)*CO2OUT(C);

*EIntensity('eMOD',FS,C,TC,TT,RUN)$SFORE_X(FS,TC) = FinalDemand('eMOD',FS,C,TC,TT,RUN)/SFORE_X(FS,TC);
*EIntensity('eGEM',FS,C,TC,TT,RUN)$SFORE_X(FS,TC) = FinalDemand('eGEM',FS,C,TC,TT,RUN)/SFORE_X(FS,TC);
*EIntensity('eMOD',FH,C,TC,XC)$TFHPOP_X(FH,TC) = FinalDemand('eMOD',FH,C,TC,XC)/TFHPOP_X(FH,TC);
*EIntensity('eGEM',FH,C,TC,XC)$TFHPOP_X(FH,TC) = FinalDemand('eGEM',FH,C,TC,XC)/TFHPOP_X(FH,TC);

*CGE_OUTPUT(A,TC,'GVA',RUN) = QVAX(A,'nat','base',TC,TT);
*CGE_OUTPUT(A,TC,'Employment',RUN) = sum(flab,QFX(flab,A,'nat','base',TC,TT));


*   QType quantitity types /qq, qd, qint, qe, qm, qh, qx, qxac/

BalanceCheck('qq',C,TC,RUN) = QQX(C,XC,TC,TT);
BalanceCheck('qd',C,TC,RUN) = QDX(C,XC,TC,TT);
BalanceCheck('qint',C,TC,RUN) = sum(A,QINTX(C,A,XC,TC,TT));
BalanceCheck('qh',C,TC,RUN) = sum(H,QHX(C,H,XC,TC,TT));
BalanceCheck('qe',C,TC,RUN) = QEX(C,'rest',XC,TC,TT);
BalanceCheck('qm',C,TC,RUN) = QMX(C,'rest',XC,TC,TT);
BalanceCheck('qx',C,TC,RUN) = QXX(C,XC,TC,TT);
BalanceCheck('qxac',C,TC,RUN) = sum(A,QXACX(A,C,XC,TC,TT));


* Checks and results for private transport modification
HH_Energy('eMOD','TRA',C,TC,RUN) = Flow_IN_FSFuels('tppr',C,TC)*0.8;
* 0.8 is the assumption that 20% of fuel is not consumed/paid for from households budgets: rental cars, govm, companies, etc.
HH_Energy('eMOD','OTH',C,TC,RUN) = sum(FH,Flow_IN_FSFuels(FH,C,TC));
*HH_Energy('eGEM','TRA',C,TC,RUN) = QINTX(C,'aprtr',XC,TC,TT);
HH_Energy('eGEM','OTH',CHEnergy,TC,RUN) = sum(H,QHX(CHEnergy,H,XC,TC,TT));
