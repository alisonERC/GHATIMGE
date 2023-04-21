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
 PQH.L(C,H)             = PQH0(C,H);
 PQI.L(C,A,RD)          = PQI0(C,A,RD);
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
 WFDIST2(F,A,RD)        = 0;
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

 pwebar(C,RW) = PWE0(C,RW);
* pwMbar(C,RW) = PWM0(C,RW);

*Reset IO coefficients to base values
 inta(A,RD) = inta0(A,RD);
 iva(A,RD) = iva0(A,RD);
 ica(C,A,RD)=ica0(C,A,RD);
 ifa(F,A,RD)=ifa0(F,A,RD);

 tui(C,A,RD) = tui0(C,A,RD);
 tuH(C,H) = tuh0(C,H);

 tm(C,RW)=tm0(C,RW);

 QINVK=0;
 NGFCF=0;

 AFX(A,RD) = NO;
 ANFX(A,RD)$(NOT AFX(A,RD)) = YES;

 ALPHAQF.L=1;

 QFBAR(FCAP,A,RD)$QF0(FCAP,A,RD)=QF0(FCAP,A,RD);

 WFK2AV(FCAP) = WFK2AV0(FCAP);

 PQ.LO('CELEC') = -inf;
 PQ.UP('CELEC') = +inf;

 tq01(C)$tq0(c) = 1;
 tq01('celec')=0;
 TQPS.FX = tqps0;
 TQELEC.FX(C) = TQELEC0(C);

 WF_BAR(F)  = WF0(F);
 QFS_BAR(F) = QFS0(F);

*Reset indirect tax share variables
 YG_DTAX.L =    YG_DTAX0 ;
 YG_ITAX.L =    YG_ITAX0 ;
 YG_NTAX.L               = YG_NTAX0 ;
 ITAXSHR.L =    ITAXSHR0 ;
 TAXADJ.L  =    TAXADJ0  ;
 GDPMP.L   =    GDPMP0   ;

* BETAM(C,H)              = betam0(C,H);
 betaca(A,C)=1;

 EPRICE(TC,TT)=PQ0('CELEC');
 EINVCOST(RUN,TC) = 0;
 INVCOST(RUN,TC,PRC) = 0;
 BPINV(RUN,TC,TCP,PRC) = 0;

 HCAP(X,TC,TT) = 0;

 ICAGR(C,A,TC) = 1;
 ICAFSGR(C,FS,TC) = 1;
 IFAGR(F,A,TC) = 1;
 IFAFSGR(F,FS,TC) = 1;

 gammamgr(C,H,TC) = 1;

 deltaq(cm,rw) = deltaq0(cm,rw);
 deltat(cm,rw) = deltat0(cm,rw);

* CMRES('CELEC') = YES;
*  CERES('CELEC') = YES;

* CERES('CCOIL') = YES;
* CMRES('CCOIL') = YES;
* QM.FX('CCOIL','REST') = QM0('CCOIL','REST');

 CERES('CPETR') = YES;
 CMRES('CPETR') = YES;
 QM.FX('CPETR','REST') = QM0('CPETR','REST');

 CERES('CNGAS') = YES;
 CMRES('CNGAS') = YES;
 QM.FX('CNGAS','REST') = QM0('CNGAS','REST');
