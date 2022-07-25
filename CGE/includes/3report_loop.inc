*-----------------------------------------------------------------------------
*Activities based tables (GDP at factor cost)
*-----------------------------------------------------------------------------

*GDP at factor cost
 GDPX(AR,XC,TC)  = SUM((A,RD)$ACTAGG(A,RD,AR), PVA0(A,RD)*QVAX(A,RD,XC,TC));

*Average annual growth in GDP at factor cost
 GDPXA(AR,XC)$SUM(T1, GDPX(AR,XC,T1)) = ((SUM(TN, GDPX(AR,XC,TN))/SUM(T1, GDPX(AR,XC,T1)))**(1/TNUM)-1)*100;

*Year-on-year growth in GDP at factor cost
 GDPXY(AR,XC,TC)$GDPX(AR,XC,TC-1) = (GDPX(AR,XC,TC)/GDPX(AR,XC,TC-1)-1)*100;

*Share of GDP at factor cost
 GDPXS(AR,XC,TC)$SUM(ARP$(NOT ARA(ARP)), GDPX(ARP,XC,TC)) = GDPX(AR,XC,TC)/SUM(ARP$(NOT ARA(ARP)), GDPX(ARP,XC,TC))*100;

*-----------------------------------------------------------------------------
*GDP at market prices (demand-side or expenditures)
*-----------------------------------------------------------------------------

*Levels
 GDPDX('ABSORP',XC,TC)   = GDPTAB1('REAL','ABSORP',XC,TC);
 GDPDX('PRVCON',XC,TC)   = GDPTAB1('REAL','PRVCON',XC,TC);
 GDPDX('FIXINV',XC,TC)   = GDPTAB1('REAL','FIXINV',XC,TC);
 GDPDX('DSTOCK',XC,TC)   = GDPTAB1('REAL','DSTOCK',XC,TC);
 GDPDX('GOVCON',XC,TC)   = GDPTAB1('REAL','GOVCON',XC,TC);
 GDPDX('EXPORTS',XC,TC)  = GDPTAB1('REAL','EXPORTS',XC,TC);
 GDPDX('IMPORTS',XC,TC)  = GDPTAB1('REAL','IMPORTS',XC,TC);
 GDPDX('GDPMP',XC,TC)    = GDPTAB1('REAL','GDPMP',XC,TC);
 GDPDX('NETITAX',XC,TC)  = GDPTAB1('REAL','NETITAX',XC,TC);
 GDPDX('GDPFC2',XC,TC)   = GDPTAB1('REAL','GDPFC2',XC,TC);

*Shares
 GDPDXS(IGDP,XC,TC)$GDPDX('GDPMP',XC,TC) =  GDPDX(IGDP,XC,TC)/GDPDX('GDPMP',XC,TC)*100;

*Year-on-year growth rates
 GDPDXY(IGDP,XC,TC)$GDPDX(IGDP,XC,TC-1) = (GDPDX(IGDP,XC,TC)/GDPDX(IGDP,XC,TC-1)-1)*100;

*Average annual growth rates
 GDPDXA(IGDP,XC)$SUM(T1, GDPDX(IGDP,XC,T1)) = ((SUM(TN, GDPDX(IGDP,XC,TN))/SUM(T1, GDPDX(IGDP,XC,T1)))**(1/TNUM)-1)*100;
 GDPDXA(IGDP,'INIT') = SUM(T1, GDPDXS(IGDP,'BASE',T1));

*-----------------------------------------------------------------------------
*Factors based tables
*-----------------------------------------------------------------------------

*Factor supplies
 FACX(FR,XC,TC)  = SUM((F,A,RD)$FACAGG(F,FR), QFX(F,A,RD,XC,TC));
*Average annual growth in factor supplies
 FACXA(FR,XC)$SUM(T1, FACX(FR,XC,T1)) = ((SUM(TN, FACX(FR,XC,TN))/SUM(T1, FACX(FR,XC,T1)))**(1/TNUM)-1)*100;
 FACXA(FR,'INIT') = SUM(T1, FACX(FR,'BASE',T1));
*Year-on-year growth in factor supplies
 FACXY(FR,XC,TC)$FACX(FR,XC,TC-1) = (FACX(FR,XC,TC)/FACX(FR,XC,TC-1)-1)*100;
 FACXY(FR,XC,T1) = FACX(FR,'BASE',T1);

*Factor returns
 FACRX(FR,XC,TC) = SUM((A,RD,F)$FACAGG(F,FR), QFX(F,A,RD,XC,TC)*WFDISTX(F,A,RD,XC,TC)*WFX(F,XC,TC)) / SUM(F$FACAGG(F,FR), QFSX(F,XC,TC)) / (CPIX(XC,TC)/CPI0);
*Average annual growth in factor returns
 FACRXA(FR,XC)$SUM(T1, FACRX(FR,XC,T1)) = ((SUM(TN, FACRX(FR,XC,TN))/SUM(T1, FACRX(FR,XC,T1)))**(1/TNUM)-1)*100;
 FACRXA(FR,'INIT') = SUM(T1, FACRX(FR,'BASE',T1));
*year-on-year growth in factor returns
 FACRXY(FR,XC,TC)$FACRX(FR,XC,TC-1) = (FACRX(FR,XC,TC)/FACRX(FR,XC,TC-1)-1)*100;
 FACRXY(FR,XC,T1) = FACRX(FR,'BASE',T1);


*-----------------------------------------------------------------------------
*Household based tables
*-----------------------------------------------------------------------------

*Household population
 POPX(HR,XC,TC) = SUM(H$HHDAGG(H,HR), HPOPX(H,XC,TC));
*Average annual household population growth
 POPXA(HR,XC)$SUM(T1, POPX(HR,XC,T1)) = ((SUM(TN, POPX(HR,XC,TN))/SUM(T1, POPX(HR,XC,T1)))**(1/TNUM)-1)*100;
*Year-on-year household population growth
 POPXY(HR,XC,TC)$POPX(HR,XC,TC-1) = (POPX(HR,XC,TC)/POPX(HR,XC,TC-1)-1)*100;

*Household real consumption
 HHDCX(HR,XC,TC) = SUM((H,C)$HHDAGG(H,HR), PQ0(C)*QHX(C,H,XC,TC)) + SUM((H,A)$HHDAGG(H,HR), PA0(A)*QHAX(A,H,XC,TC));
*Average annual growth in household real consumption
 HHDCXA(HR,XC)$SUM(T1, HHDCX(HR,XC,T1)) = ((SUM(TN, HHDCX(HR,XC,TN))/SUM(T1, HHDCX(HR,XC,T1)))**(1/TNUM)-1)*100;
 HHDCXA(HR,'INIT') = SUM(T1, HHDCX(HR,'BASE',T1));
*Year-on-year growth in household real consumption
 HHDCXY(HR,XC,TC)$HHDCX(HR,XC,TC-1) = (HHDCX(HR,XC,TC)/HHDCX(HR,XC,TC-1)-1)*100;
 HHDCXY(HR,XC,T1) = HHDCX(HR,'BASE',T1);

*Household real per capita consumption
 HHDPCX(HR,XC,TC) = HHDCX(HR,XC,TC) / POPX(HR,XC,TC) * 1000;
*Average annual growth in per capita household real consumption
 HHDPCXA(HR,XC)$SUM(T1, HHDPCX(HR,XC,T1)) = ((SUM(TN, HHDPCX(HR,XC,TN))/SUM(T1, HHDPCX(HR,XC,T1)))**(1/TNUM)-1)*100;
 HHDPCXA(HR,'INIT') = SUM(T1, HHDPCX(HR,'BASE',T1));
*Year-on-year growth in per capita household real consumption
 HHDPCXY(HR,XC,TC)$HHDPCX(HR,XC,TC-1) = (HHDPCX(HR,XC,TC)/HHDPCX(HR,XC,TC-1)-1)*100;
 HHDPCXY(HR,XC,T1) = HHDPCX(HR,'BASE',T1);

*Base year household consumption patterns
 HHDBC(CR,HR)$SUM((H,C)$HHDAGG(H,HR), SAM(C,H)) = SUM((H,C)$(COMAGG(C,CR) AND HHDAGG(H,HR)), SAM(C,H)) / SUM((H,C)$HHDAGG(H,HR), SAM(C,H))*100;

*Base year household income patterns
 HHDBY(HR,FR) = SUM((H,F)$(FACAGG(F,FR) AND HHDAGG(H,HR)), SAM(H,F)) / SUM((ACNT,H)$HHDAGG(H,HR), SAM(H,ACNT))*100;
 HHDBY(HR,'hENT') = SUM((EN,H)$HHDAGG(H,HR), SAM(H,EN)) / SUM((ACNT,H)$HHDAGG(H,HR), SAM(H,ACNT))*100;
 HHDBY(HR,'hGOV') = SUM(H$HHDAGG(H,HR), SAM(H,'GOV')) / SUM((ACNT,H)$HHDAGG(H,HR), SAM(H,ACNT))*100;
 HHDBY(HR,'hROW') = SUM(H$HHDAGG(H,HR), SAM(H,'ROW')) / SUM((ACNT,H)$HHDAGG(H,HR), SAM(H,ACNT))*100;
 HHDBY(HR,'hTOT') = HHDBY(HR,'xLABOR') + HHDBY(HR,'xCAPITAL') + HHDBY(HR,'hENT') + HHDBY(HR,'hGOV') + HHDBY(HR,'hROW');

*-----------------------------------------------------------------------------
*Foreign trade tables
*-----------------------------------------------------------------------------

*Real imports and exports
 TREX(CR,XC,TC) = SUM((C,RW)$COMAGG(C,CR), pwe0(C,RW)*EXR0*QEX(C,RW,XC,TC));
 TRMX(CR,XC,TC) = SUM((C,RW)$COMAGG(C,CR), pwm0(C,RW)*EXR0*QMX(C,RW,XC,TC));
 NETX(CR,XC,TC) = TREX(CR,XC,TC) - TRMX(CR,XC,TC);

*Average annual growth in real imports and exports
 TREXA(CR,XC)$SUM(T1, TREX(CR,XC,T1)) = ((SUM(TN, TREX(CR,XC,TN))/SUM(T1, TREX(CR,XC,T1)))**(1/TNUM)-1)*100;
 TRMXA(CR,XC)$SUM(T1, TRMX(CR,XC,T1)) = ((SUM(TN, TRMX(CR,XC,TN))/SUM(T1, TRMX(CR,XC,T1)))**(1/TNUM)-1)*100;
 TREXA(CR,'INIT') = SUM(T1, TREX(CR,'BASE',T1))/SUM(T1, TREX('zGDP','BASE',T1))*100;
 TRMXA(CR,'INIT') = SUM(T1, TRMX(CR,'BASE',T1))/SUM(T1, TRMX('zGDP','BASE',T1))*100;

*Year-on-year growth in real imports and exports
 TREXY(CR,XC,TC)$TREX(CR,XC,TC-1) = (TREX(CR,XC,TC)/TREX(CR,XC,TC-1)-1)*100;
 TRMXY(CR,XC,TC)$TRMX(CR,XC,TC-1) = (TRMX(CR,XC,TC)/TRMX(CR,XC,TC-1)-1)*100;

*-----------------------------------------------------------------------------
*Structural base table with aggregates
*-----------------------------------------------------------------------------

 STRUCBASE2(AR,'VAshr')  = SUM(T1, GDPXS(AR,'BASE',T1));
 STRUCBASE2(AR,'PRDshr') = SUM((RD,A)$ACTAGG(A,RD,AR), PAR0(A,RD)*(1-tva0(A,RD))*QAR0(A,RD)) / SUM((RD,A), PAR0(A,RD)*(1-tva0(A,RD))*QAR0(A,RD)) * 100;
 STRUCBASE2(AR,'EMPshr') = SUM((FLAB,A,RD)$ACTAGG(A,RD,AR), QF0(FLAB,A,RD)) / SUM((FLAB,A,RD), QF0(FLAB,A,RD)) * 100;
 STRUCBASE3(CR,'EXPshr') = SUM((RW,C)$COMAGG(C,CR), pwe0(C,RW)*EXR0*QE0(C,RW)) / SUM((RW,C), pwe0(C,RW)*EXR0*QE0(C,RW)) * 100;
 STRUCBASE3(CR,'IMPshr') = SUM((RW,C)$COMAGG(C,CR), pwm0(C,RW)*EXR0*QM0(C,RW)) / SUM((RW,C), pwm0(C,RW)*EXR0*QM0(C,RW)) * 100;

 STRUCBASE3(CR,'EXP-OUTshr')$SUM(C$COMAGG(C,CR), PX0(C)*QX0(C)) = SUM((RW,C)$COMAGG(C,CR), PE0(C,RW)*EXR0*QE0(C,RW)) / SUM((A,C)$COMAGG(C,CR), PXAC0(A,C)*QXAC0(A,C)) * 100;
 STRUCBASE3(CR,'IMP-DEMshr')$SUM(C$COMAGG(C,CR), PQ0(C)*(1-tq0(C))*QQ0(C)) = SUM((RW,C)$COMAGG(C,CR), PM0(C,RW)*EXR0*QM0(C,RW)) / SUM(C$COMAGG(C,CR), PQ0(C)*(1-tq0(C))*QQ0(C)) * 100;

 STRUCBASE2('xGDP','VAshr')  = SUM(AR$(NOT ARA(AR)), STRUCBASE2(AR,'VAshr') );
 STRUCBASE2('xGDP','PRDshr') = SUM(AR$(NOT ARA(AR)), STRUCBASE2(AR,'PRDshr'));
 STRUCBASE2('xGDP','EMPshr') = SUM(AR$(NOT ARA(AR)), STRUCBASE2(AR,'EMPshr'));
 STRUCBASE3('zGDP','EXPshr') = SUM(CR$(NOT CRA(CR)), STRUCBASE3(CR,'EXPshr'));
 STRUCBASE3('zGDP','IMPshr') = SUM(CR$(NOT CRA(CR)), STRUCBASE3(CR,'IMPshr'));

*-----------------------------------------------------------------------------
*Exporting to MS-EXCEL
*-----------------------------------------------------------------------------

SETS
 TAC     / SALVAL, SRATE, SCOL, IMPVAL, TRATE, TCOL /
 GAC     / TOTGINC, ATAXCOL, HTAXCOL, ETAXCOL, MTAXCOL, STAXCOL, FACTINC, TRNSINC, TOTGEXP, GCONSTT, TRNHEXP, TRNEEXP, TOTGSAV /
;

PARAMETER
 GDPXATAB(AR,X)     Baseline average annual GDP growth rate
 PVAXATAB(AR,X)     Value-added price annual growth rate
 PAXATAB(AR,X)      Activity price annual growth rate
 PXXATAB(CR,X)      Output price annual growth rate
 PQXATAB(CR,X)      Output price annual growth rate
 PEXATAB(CR,X)      Output price annual growth rate
 PMXATAB(CR,X)      Output price annual growth rate
 PWEXATAB(CR,X)     Output price annual growth rate
 PWMXATAB(CR,X)     Output price annual growth rate
 FACXATAB(FR,X)     Average annual factor supply growth rate for all sims
 FACRXATAB(FR,X)    Average annual factor supply growth rate for all sims
 POPXATAB(HR,X)     Average annual household population growth
 HHDCXATAB(HR,X)    Average annual household consumption growth
 HHDPCXATAB(HR,X)   Average annual household per capita consumption growth
 TAXESTAB(CR,TAC)   Sales and import tariff tax rates
 GOVERNTAB(GAC,X)   Government fiscal table shares
 GOVERNTAB2(GAC,X)  Government fiscal table growth
;

*Simulations: GDP table with initial GDP shares
 GDPXATAB(AR,XC) = GDPXA(AR,XC);
 GDPXATAB(AR,XNB)$GDPXATAB(AR,XNB) = GDPXATAB(AR,XNB) - GDPXATAB(AR,'BASE');
 GDPXATAB(AR,'INIT') = SUM(T1, GDPXS(AR,'BASE',T1));
 GDPXATAB(AR,X)$(NOT GDPXATAB(AR,X)) = 0.0000001;

*Simulations: Macroeconomic indicators table
 MACROTAB(SIND,X)$(NOT MACROTAB(SIND,X)) = 0.0000001;

*Simulations: GDP demand-side table
 GDPDXA(IGDP,XNB)$GDPDXA(IGDP,XNB) = GDPDXA(IGDP,XNB) - GDPDXA(IGDP,'BASE');
 GDPDXA(IGDP,X)$(NOT GDPDXA(IGDP,X)) = 0.0000001;

*Simulations: Trade results
 TREXA(CR,XNB)$TREXA(CR,XNB) = TREXA(CR,XNB) - TREXA(CR,'BASE');
 TRMXA(CR,XNB)$TRMXA(CR,XNB) = TRMXA(CR,XNB) - TRMXA(CR,'BASE');
 TREXA(CR,X)$(NOT TREXA(CR,X)) = 0.0000001;
 TRMXA(CR,X)$(NOT TRMXA(CR,X)) = 0.0000001;

*Simulation: Value-added prices
 PVAXATAB(AR,XC)$SUM((A,RD)$ACTAGG(A,RD,AR), QVA0(A,RD)) = SUM((TN,A,RD)$ACTAGG(A,RD,AR), PVAX(A,RD,XC,TN)*PVA0(A,RD)*QVA0(A,RD) / SUM((RDP,AP)$(ACTAGG(A,RD,AR) AND ACTAGG(AP,RDP,AR)), PVA0(AP,RDP)*QVA0(AP,RDP)));
 PVAXATAB(AR,'INIT')$SUM((RD,A)$ACTAGG(A,RD,AR), QVA0(A,RD)) = SUM((RD,A)$ACTAGG(A,RD,AR), PVA0(A,RD)*PVA0(A,RD)*QVA0(A,RD) / SUM((RDP,AP)$(ACTAGG(A,RD,AR) AND ACTAGG(AP,RDP,AR)), PVA0(AP,RDP)*QVA0(AP,RDP)));
 PVAXATAB(AR,XC)$PVAXATAB(AR,'INIT') = ((PVAXATAB(AR,XC)/PVAXATAB(AR,'INIT'))**(1/TNUM)-1)*100;
 PVAXATAB(AR,'INIT')$SUM((RD,A), PVA0(A,RD)*QVA0(A,RD)) = SUM((A,RD)$ACTAGG(A,RD,AR), PVA0(A,RD)*QVA0(A,RD)) / SUM((RD,A), PVA0(A,RD)*QVA0(A,RD))*100;
 PVAXATAB(AR,XNB)$PVAXATAB(AR,XNB) = PVAXATAB(AR,XNB) - PVAXATAB(AR,'BASE');
 PVAXATAB(AR,X)$(NOT PVAXATAB(AR,X)) = 0.0000001;

*Simulation: Output prices
 PXXATAB(CR,XC)$SUM(C$COMAGG(C,CR), QX0(C)) = SUM((TN,C)$COMAGG(C,CR), PXX(C,XC,TN)*PX0(C)*QX0(C) / SUM(CP$(COMAGG(C,CR) AND COMAGG(CP,CR)), PX0(CP)*QX0(CP)));
 PXXATAB(CR,'INIT')$SUM(C$COMAGG(C,CR), QX0(C)) = SUM(C$COMAGG(C,CR), PX0(C)*PX0(C)*QX0(C) / SUM(CP$(COMAGG(C,CR) AND COMAGG(CP,CR)), PX0(CP)*QX0(CP)));
 PXXATAB(CR,XC)$PXXATAB(CR,'INIT') = ((PXXATAB(CR,XC)/PXXATAB(CR,'INIT'))**(1/TNUM)-1)*100;
 PXXATAB(CR,'INIT')$SUM(C, PX0(C)*QX0(C)) = SUM(C$COMAGG(C,CR), PX0(C)*QX0(C)) / SUM(C, PX0(C)*QX0(C))*100;
 PXXATAB(CR,XNB)$PXXATAB(CR,XNB) = PXXATAB(CR,XNB) - PXXATAB(CR,'BASE');
 PXXATAB(CR,X)$(NOT PXXATAB(CR,X)) = 0.0000001;

*Simulation: Composite supply prices
 PQXATAB(CR,XC)$SUM(C$COMAGG(C,CR), QQ0(C)) = SUM((TN,C)$COMAGG(C,CR), PQX(C,XC,TN)*PQ0(C)*QQ0(C) / SUM(CP$(COMAGG(C,CR) AND COMAGG(CP,CR)), PQ0(CP)*QQ0(CP)));
 PQXATAB(CR,'INIT')$SUM(C$COMAGG(C,CR), QQ0(C)) = SUM(C$COMAGG(C,CR), PQ0(C)*PQ0(C)*QQ0(C) / SUM(CP$(COMAGG(C,CR) AND COMAGG(CP,CR)), PQ0(CP)*QQ0(CP)));
 PQXATAB(CR,XC)$PQXATAB(CR,'INIT') = ((PQXATAB(CR,XC)/PQXATAB(CR,'INIT'))**(1/TNUM)-1)*100;
 PQXATAB(CR,'INIT')$SUM(C, PQ0(C)*QQ0(C)) = SUM(C$COMAGG(C,CR), PQ0(C)*QQ0(C)) / SUM(C, PQ0(C)*QQ0(C))*100;
 PQXATAB(CR,XNB)$PQXATAB(CR,XNB) = PQXATAB(CR,XNB) - PQXATAB(CR,'BASE');
 PQXATAB(CR,X)$(NOT PQXATAB(CR,X)) = 0.0000001;

*Simulation: Export prices
 PEXATAB(CR,XC)$SUM((C,RW)$COMAGG(C,CR), QE0(C,RW)) = SUM((TN,C,RW)$COMAGG(C,CR), PEX(C,RW,XC,TN)*PE0(C,RW)*QE0(C,RW) / SUM((RWP,CP)$(COMAGG(C,CR) AND COMAGG(CP,CR)), PE0(CP,RWP)*QE0(CP,RWP)));
 PEXATAB(CR,'INIT')$SUM((RW,C)$COMAGG(C,CR), QE0(C,RW)) = SUM((RW,C)$COMAGG(C,CR), PE0(C,RW)*PE0(C,RW)*QE0(C,RW) / SUM((RWP,CP)$(COMAGG(C,CR) AND COMAGG(CP,CR)), PE0(CP,RWP)*QE0(CP,RWP)));
 PEXATAB(CR,XC)$PEXATAB(CR,'INIT') = ((PEXATAB(CR,XC)/PEXATAB(CR,'INIT'))**(1/TNUM)-1)*100;
 PEXATAB(CR,'INIT')$SUM((RW,C), PE0(C,RW)*QE0(C,RW)) = SUM((C,RW)$COMAGG(C,CR), PE0(C,RW)*QE0(C,RW)) / SUM((RW,C), PE0(C,RW)*QE0(C,RW))*100;
 PEXATAB(CR,XNB)$PEXATAB(CR,XNB) = PEXATAB(CR,XNB) - PEXATAB(CR,'BASE');
 PEXATAB(CR,X)$(NOT PEXATAB(CR,X)) = 0.0000001;

*Simulation: Import prices
 PMXATAB(CR,XC)$SUM((C,RW)$COMAGG(C,CR), QM0(C,RW)) = SUM((TN,C,RW)$COMAGG(C,CR), PMX(C,RW,XC,TN)*PM0(C,RW)*QM0(C,RW) / SUM((RWP,CP)$(COMAGG(C,CR) AND COMAGG(CP,CR)), PM0(CP,RWP)*QM0(CP,RWP)));
 PMXATAB(CR,'INIT')$SUM((RW,C)$COMAGG(C,CR), QM0(C,RW)) = SUM((RW,C)$COMAGG(C,CR), PM0(C,RW)*PM0(C,RW)*QM0(C,RW) / SUM((RWP,CP)$(COMAGG(C,CR) AND COMAGG(CP,CR)), PM0(CP,RWP)*QM0(CP,RWP)));
 PMXATAB(CR,XC)$PMXATAB(CR,'INIT') = ((PMXATAB(CR,XC)/PMXATAB(CR,'INIT'))**(1/TNUM)-1)*100;
 PMXATAB(CR,'INIT')$SUM((RW,C), PM0(C,RW)*QM0(C,RW)) = SUM((C,RW)$COMAGG(C,CR), PM0(C,RW)*QM0(C,RW)) / SUM((RW,C), PM0(C,RW)*QM0(C,RW))*100;
 PMXATAB(CR,XNB)$PMXATAB(CR,XNB) = PMXATAB(CR,XNB) - PMXATAB(CR,'BASE');
 PMXATAB(CR,X)$(NOT PMXATAB(CR,X)) = 0.0000001;

*Simulation: World export prices
 PWEXATAB(CR,XC)$SUM((C,RW)$COMAGG(C,CR), QE0(C,RW)) = SUM((TN,C,RW)$COMAGG(C,CR), PWEX(C,RW,XC,TN)*PWE0(C,RW)*QE0(C,RW) / SUM((RWP,CP)$(COMAGG(C,CR) AND COMAGG(CP,CR)), PWE0(CP,RWP)*QE0(CP,RWP)));
 PWEXATAB(CR,'INIT')$SUM((RW,C)$COMAGG(C,CR), QE0(C,RW)) = SUM((RW,C)$COMAGG(C,CR), PWE0(C,RW)*PWE0(C,RW)*QE0(C,RW) / SUM((RWP,CP)$(COMAGG(C,CR) AND COMAGG(CP,CR)), PWE0(CP,RWP)*QE0(CP,RWP)));
 PWEXATAB(CR,XC)$PWEXATAB(CR,'INIT') = ((PWEXATAB(CR,XC)/PWEXATAB(CR,'INIT'))**(1/TNUM)-1)*100;
 PWEXATAB(CR,'INIT')$SUM((RW,C), PWE0(C,RW)*QE0(C,RW)) = SUM((C,RW)$COMAGG(C,CR), PWE0(C,RW)*QE0(C,RW)) / SUM((RW,C), PWE0(C,RW)*QE0(C,RW))*100;
 PWEXATAB(CR,XNB)$PWEXATAB(CR,XNB) = PWEXATAB(CR,XNB) - PWEXATAB(CR,'BASE');
 PWEXATAB(CR,X)$(NOT PWEXATAB(CR,X)) = 0.0000001;

*Simulation: World import prices
 PWMXATAB(CR,XC)$SUM((C,RW)$COMAGG(C,CR), QM0(C,RW)) = SUM((TN,C,RW)$COMAGG(C,CR), PWMX(C,RW,XC,TN)*PWM0(C,RW)*QM0(C,RW) / SUM((RWP,CP)$(COMAGG(C,CR) AND COMAGG(CP,CR)), PWM0(CP,RWP)*QM0(CP,RWP)));
 PWMXATAB(CR,'INIT')$SUM((RW,C)$COMAGG(C,CR), QM0(C,RW)) = SUM((RW,C)$COMAGG(C,CR), PWM0(C,RW)*PWM0(C,RW)*QM0(C,RW) / SUM((RWP,CP)$(COMAGG(C,CR) AND COMAGG(CP,CR)), PWM0(CP,RWP)*QM0(CP,RWP)));
 PWMXATAB(CR,XC)$PWMXATAB(CR,'INIT') = ((PWMXATAB(CR,XC)/PWMXATAB(CR,'INIT'))**(1/TNUM)-1)*100;
 PWMXATAB(CR,'INIT')$SUM((RW,C), PWM0(C,RW)*QM0(C,RW)) = SUM((C,RW)$COMAGG(C,CR), PWM0(C,RW)*QM0(C,RW)) / SUM((RW,C), PWM0(C,RW)*QM0(C,RW))*100;
 PWMXATAB(CR,XNB)$PWMXATAB(CR,XNB) = PWMXATAB(CR,XNB) - PWMXATAB(CR,'BASE');
 PWMXATAB(CR,X)$(NOT PWMXATAB(CR,X)) = 0.0000001;

*Simulations: Average annual factor supply growth rate
 FACXATAB(FR,XC) = FACXA(FR,XC);
 FACXATAB(FR,'INIT') = SUM(T1, FACX(FR,'BASE',T1));
 FACXATAB(FR,XNB)$FACXATAB(FR,XNB) = FACXATAB(FR,XNB) - FACXATAB(FR,'BASE');
 FACXATAB(FR,X)$(NOT FACXATAB(FR,X)) = 0.0000001;

*Simulations: Average annual factor returns growth rate
 FACRXATAB(FR,XC) = FACRXA(FR,XC);
 FACRXATAB(FR,'INIT') = SUM(T1, FACX(FR,'BASE',T1));
 FACRXATAB(FR,XNB)$FACRXATAB(FR,XNB) = FACRXATAB(FR,XNB) - FACRXATAB(FR,'BASE');
 FACRXATAB(FR,X)$(NOT FACRXATAB(FR,X)) = 0.0000001;

*Simulations: Average annual household population growth
 POPXATAB(HR,XC) = POPXA(HR,XC);
 POPXATAB(HR,'INIT') = SUM(T1, POPX(HR,'BASE',T1));
 POPXATAB(HR,XNB)$POPXATAB(HR,XNB) = POPXATAB(HR,XNB) - POPXATAB(HR,'BASE');
 POPXATAB(HR,X)$(NOT POPXATAB(HR,X)) = 0.0000001;

*Simulations: Average annual household consumption growth
 HHDCXATAB(HR,XC) = HHDCXA(HR,XC);
 HHDCXATAB(HR,'INIT') = SUM(T1, HHDCX(HR,'BASE',T1));
 HHDCXATAB(HR,XNB)$HHDCXATAB(HR,XNB) = HHDCXATAB(HR,XNB) - HHDCXATAB(HR,'BASE');
 HHDCXATAB(HR,X)$(NOT HHDCXATAB(HR,X)) = 0.0000001;

*Simulations: Average annual household per capita consumption growth
 HHDPCXATAB(HR,XC) = HHDPCXA(HR,XC);
 HHDPCXATAB(HR,'INIT') = SUM(T1, HHDPCX(HR,'BASE',T1));
 HHDPCXATAB(HR,XNB)$HHDPCXATAB(HR,XNB) = HHDPCXATAB(HR,XNB) - HHDPCXATAB(HR,'BASE');
 HHDPCXATAB(HR,X)$(NOT HHDPCXATAB(HR,X)) = 0.0000001;

*Base year: Sales taxes and tariffs
 TAXESTAB(CR,'SALVAL')$SUM(C, PQ0(C)*QQ0(C)) = SUM(C$COMAGG(C,CR), PQ0(C)*QQ0(C))/SUM(C, PQ0(C)*QQ0(C))*100;
 TAXESTAB(CR,'SRATE')$SUM(C$COMAGG(C,CR), PQ0(C)*QQ0(C)) = SUM(C$COMAGG(C,CR), tq0(C)*PQ0(C)*QQ0(C))/SUM(C$COMAGG(C,CR), PQ0(C)*QQ0(C))*100;
 TAXESTAB(CR,'SCOL')$SUM(C, tq0(C)*PQ0(C)*QQ0(C))       = SUM(C$COMAGG(C,CR), tq0(C)*PQ0(C)*QQ0(C))/SUM(C, tq0(C)*PQ0(C)*QQ0(C))*100;
 TAXESTAB(CR,'IMPVAL')$SUM((RW,C), PM0(C,RW)*QM0(C,RW)) = SUM((RW,C)$COMAGG(C,CR), PM0(C,RW)*QM0(C,RW))/SUM((RW,C), PM0(C,RW)*QM0(C,RW))*100;
 TAXESTAB(CR,'TRATE')$SUM((RW,C)$COMAGG(C,CR), PM0(C,RW)*QM0(C,RW))  = SUM((RW,C)$COMAGG(C,CR), tm0(C,RW)*PM0(C,RW)*QM0(C,RW))/SUM((RW,C)$COMAGG(C,CR), PM0(C,RW)*QM0(C,RW))*100;
 TAXESTAB(CR,'TCOL') $SUM((RW,C), tm0(C,RW)*PM0(C,RW)*QM0(C,RW))    = SUM((RW,C)$COMAGG(C,CR), tm0(C,RW)*PM0(C,RW)*QM0(C,RW))/SUM((RW,C), tm0(C,RW)*PM0(C,RW)*QM0(C,RW))*100;
 TAXESTAB(CR,TAC)$(NOT TAXESTAB(CR,TAC)) = 0.0000001;

*Simulations: Government fiscal table
 GOVERNTAB('TOTGINC',XC) = SUM(TN, YGX(XC,TN));
 GOVERNTAB('ATAXCOL',XC) = SUM((A,RD,TN), TAX(A,RD,XC,TN)*PARX(A,RD,XC,TN)*QARX(A,RD,XC,TN));
 GOVERNTAB('HTAXCOL',XC) = SUM((H,TN), TINSX(H,XC,TN)*YIX(H,XC,TN));
 GOVERNTAB('ETAXCOL',XC) = SUM((EN,TN), TINSX(EN,XC,TN)*YIX(EN,XC,TN));
 GOVERNTAB('MTAXCOL',XC) = SUM((CM,RW,TN), tmx(CM,RW,XC,TN)*PWMX(CM,RW,XC,TN)*QMX(CM,RW,XC,TN)*EXRX(XC,TN));
 GOVERNTAB('STAXCOL',XC) = SUM((C,TN), tqx(C,XC,TN)*PQX(C,XC,TN)*QQX(C,XC,TN));
 GOVERNTAB('FACTINC',XC) = SUM((F,TN), YIFX('GOV',F,XC,TN));
 GOVERNTAB('TRNSINC',XC) = SUM(TN, trnsfrx('GOV','ROW',XC,TN)*EXRX(XC,TN));
 GOVERNTAB('TOTGINC','INIT') = YG0;
 GOVERNTAB('ATAXCOL','INIT') = SUM((A,RD), TA0(A,RD)*PAR0(A,RD)*QAR0(A,RD));
 GOVERNTAB('HTAXCOL','INIT') = SUM(H, TINS0(H)*YI0(H));
 GOVERNTAB('ETAXCOL','INIT') = SUM(EN, TINS0(EN)*YI0(EN));
 GOVERNTAB('MTAXCOL','INIT') = SUM((CM,RW), tm0(CM,RW)*PWM0(CM,RW)*QM0(CM,RW)*EXR0);
 GOVERNTAB('STAXCOL','INIT') = SUM(C, tq0(C)*PQ0(C)*QQ0(C));
 GOVERNTAB('FACTINC','INIT') = SUM(F, YIF0('GOV',F));
 GOVERNTAB('TRNSINC','INIT') = trnsfr0('GOV','ROW')*EXR0;
 GOVERNTAB('TOTGEXP',XC) = SUM(TN, EGX(XC,TN));
 GOVERNTAB('GCONSTT',XC) = SUM((TN,C), PQX(C,XC,TN)*QGX(C,XC,TN));
 GOVERNTAB('TRNHEXP',XC) = SUM((TN,H), trnsfrx(H,'GOV',XC,TN)*CPIX(XC,TN));
 GOVERNTAB('TRNEEXP',XC) = SUM((TN,EN), trnsfrx(EN,'GOV',XC,TN)*CPIX(XC,TN));
 GOVERNTAB('TOTGSAV',XC) = SUM(TN, GSAVX(XC,TN));
 GOVERNTAB('TOTGEXP','INIT') = EG0;
 GOVERNTAB('GCONSTT','INIT') = SUM(C, PQ0(C)*QG0(C));
 GOVERNTAB('TRNHEXP','INIT') = SUM(H, trnsfr0(H,'GOV')*CPI0);
 GOVERNTAB('TRNEEXP','INIT') = SUM(EN, trnsfr0(EN,'GOV')*CPI0);
 GOVERNTAB('TOTGSAV','INIT') = GSAV0;


* GOVERNTAB2(GAC,XC)$GOVERNTAB(GAC,'INIT') = ((GOVERNTAB(GAC,XC)/GOVERNTAB(GAC,'INIT'))**(1/TNUM)-1)*100;
 GOVERNTAB(GAC,X)$GOVERNTAB('TOTGINC',X) = GOVERNTAB(GAC,X) / GOVERNTAB('TOTGINC',X)*100;

 GOVERNTAB2(GAC,'INIT') = GOVERNTAB(GAC,'INIT');

 GOVERNTAB(GAC,X)$(NOT GOVERNTAB(GAC,X)) = 0.0000001;
 GOVERNTAB2(GAC,X)$(NOT GOVERNTAB2(GAC,X)) = 0.0000001;












*-----------------------------------------------------------------------------
*Writing results to Excel
*-----------------------------------------------------------------------------

$exit
PARAMETER XLTEST;
execute_unload "00output.gdx" STRUCBASE2 STRUCBASE3 GDPXATAB MACROTAB GDPDXA TREXA TRMXA PVAXATAB PXXATAB PQXATAB PEXATAB PMXATAB PWEXATAB PWMXATAB FACXATAB FACRXATAB POPXATAB HHDCXATAB HHDPCXATAB TAXESTAB HHDBC HHDBY GOVERNTAB GOVERNTAB2
execute 'xlstalk.exe -m 00output.xlsx';
 XLTEST = ERRORLEVEL;
IF(XLTEST = 1,
execute 'xlstalk.exe -c 00output.xlsx';
);
IF(XLTEST = 2,
execute 'xlstalk.exe -s 00output.xlsx';
);
execute 'gdxxrw.exe i=00output.gdx o=00output.xlsx index=index!a6';
execute 'xlstalk.exe -o 00output.xlsx';
DISPLAY XLTEST;







