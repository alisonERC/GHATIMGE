 CPI.L                  = CPI0;
 DMPS.L                 = DMPS0;
 DPI.L                  = DPI0;
 DTINS.L                = DTINS0;
 EG.L                   = EG0;
 EH.L(H)                = EH0(H);
 EXR.L                  = EXR0;
 FSAV.L                 = FSAV0;
 GADJ.L                 = GADJ0;
 GOVSHR.L               = GOVSHR0;
 GSAV.L                 = GSAV0;
 IADJ.L(IT)             = IADJ0(IT);
 INVSHR.L               = INVSHR0;
 MPS.L(INSDNG)          = MPS0(INSDNG);
 MPSADJ.L               = MPSADJ0;
 PA.L(A)                = PA0(A);
 PAR.L(A,RD)            = PAR0(A,RD);
 PDD.L(C)               = PDD0(C);
 PDS.L(C)               = PDS0(C);
 PINTA.L(A,RD)          = PINTA0(A,RD) ;
 PE.L(C,RW)             = PE0(C,RW);
 PM.L(C,RW)             = PM0(C,RW);
 PQ.L(C)                = PQ0(C);
 PVA.L(A,RD)            = PVA0(A,RD);
 PX.L(C)                = PX0(C);
 PXAC.L(A,C)            = PXAC0(A,C);
 QA.L(A)                = QA0(A);
 QAR.L(A,RD)            = QAR0(A,RD);
 QD.L(C)                = QD0(C);
 QE.L(C,RW)             = QE0(C,RW);
 QF.L(F,A,RD)           = QF0(F,A,RD);
 QFS0(F)                = QFS00(F);
 QFS.L(F)               = QFS0(F);
 QG.L(C)                = QG0(C);
 QH.L(C,H)              = QH0(C,H);
 QHA.L(A,H)             = QHA0(A,H);
 QINT.L(C,A)            = QINT0(C,A);
 QINTA.L(A,RD)          = QINTA0(A,RD) ;
 QINV.L(C,IT)           = QINV0(C,IT);
 QM.L(C,RW)             = QM0(C,RW);
 QQ.L(C)                = QQ0(C);
 QT.L(C)                = QT0(C);
 QVA.L(A,RD)            = QVA0(A,RD);
 QX.L(C)                = QX0(C);
 QXAC.L(A,C)            = QXAC0(A,C);
 TA.L(A,RD)             = TA0(A,RD);
 TAADJ.L                = TAADJ0;
 TABS.L                 = TABS0;
 TAPS.L                 = TAPS0;
 TQADJ.L                = TQADJ0;
 TQ.L(C)                = TQ0(C);
 TQPS.L                 = TQPS0;
 TRII.L(INSDNG,INSDNGP) = TRII0(INSDNG,INSDNGP);
 TINS.L(INSDNG)         = TINS0(INSDNG);
 TINSADJ.L              = TINSADJ0;
 WALRAS.L               = WALRAS0;
 WALRASSQR.L            = 0 ;
 WF.L(F)                = WF0(F);
 WFDIST.L(F,A,RD)       = WFDIST0(F,A,RD);
 YF.L(F)                = YF0(f);
 YG.L                   = YG0;
 YI.L(INS)              = YI0(INS);
 YIF.L(INS,F)           = YIF0(INS,F);

 gammam(C,H)            = gammam0(C,H);
 gammah(A,H)            = gammah0(A,H);
 PWE.L(C,RW)            = pwe0(C,RW);
 PWM.L(C,RW)            = pwm0(C,RW);
 trnsfr(INS,AC)         = trnsfr0(INS,AC);
 fprd(F,A,RD)$QF0(F,A,RD) = 1;

 alphava(A,RD)          = alphava0(A,RD);
 hpop(H)                = hpop0(H);

 betam(C,H) = betam0(C,H);
 debt = debt0;

*Reset IO coefficients to base values
 ica(C,A,RD)=ica0(C,A,RD);
 ifa(F,A,RD)             = ifa0(F,A,RD);

 YG_DTAX.L               = YG_DTAX0 ;
 YG_ITAX.L               = YG_ITAX0 ;
 YG_NTAX.L               = YG_NTAX0 ;
* ITAXSHR.L               = ITAXSHR0 ;
* TAXADJ.L                = TAXADJ0  ;
 GDPMP.L                 = GDPMP0;
 PQH.L(C,H)              = PQH0(C,H);
 PQI.L(C,A,RD)           = PQI0(C,A,RD);

$ontext
 inta(A,RD)              = inta0(A,RD);
 ica(C,A,RD)             = ica0(C,A,RD);
 tui(C,A,RD)             = tui0(C,A,RD);
 tuH(C,H)                = tuh0(C,H);
$offtext

* TVA.L(A,RD)             = TVA0(A,RD);
* TVAADJ.L                = TVAADJ0;
* TVAPS.L                 = TVAPS0;
 BETAM(C,H)              = betam0(C,H);
 YG_DTAX.L               = YG_DTAX0;
 YG_ITAX.L               = YG_ITAX0;
 YG_NTAX.L               = YG_NTAX0;

*! ETPRICE(TC) = PQ0('CELEC');
*! EPRICE(TC,TT)=PQ0('CELEC');
 EINVCOST(RUN,TC) = 0;
 INVCOST(RUN,TC,PRC) = 0;
 BPINV(RUN,TC,TCP,PRC) = 0;

 ICAGR(C,A,TC) = 1;
 ICAFSGR(C,FS,TC) = 1;
 IFAGR(F,A,TC) = 1;
 IFAFSGR(F,FS,TC) = 1;