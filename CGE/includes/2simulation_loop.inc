*----------------------------------------------------------------------
*4. Time period loop
*----------------------------------------------------------------------





LOOP(XC$MRUNX(RUN,XC),
 execute_load "dem_start.gdx" ELCDEM
 execute_unload "EnergyDemand.gdx" ELCDEM

 LOOP(TT$(NOT fail),

$include cge\includes\2varinit.inc

if(SIM_eMOD(RUN) eq 1,

* Write Drivers to DMD_PROJ workbook
*         execute 'gdxxrw.exe i=drivers.gdx o=.\eMOD\DataSpreadsheets\DMD_PRJ.xlsx index=index_G2E!a6';
* Read resulting Demand from DMD_PROJ workbook
*         execute 'gdxxrw.exe i=.\eMOD\DataSpreadsheets\DMD_PRJ.xlsx o=EnergyDemand.gdx index=index_E2G!a6';
*         execute_load "EnergyDemand.gdx" SIM_DEMX;
          execute_load "EnergyDemand.gdx" ELCDEM;
          SIM_DEMX(DEM1,TC) = SUM(FSeMOD$MELCDEM(FSeMOD,DEM1),ELCDEM(FSeMOD,TC));
* Need to Add Occupancy and Freight loading per vehicle category to calculate pkm and tkm

* Adjust Transport Demand
*  LOOP(TC$(ORD(TC) gt 6),
*        SIM_DEMX(TPPR,TC)$(SUM(H,QHX('cprtr',H,XC,TC-1,TT-1))) = SIM_DEMX(TPPR,TC-1)*SUM(H,QHX('cprtr',H,XC,TC,TT-1))/SUM(H,QHX('cprtr',H,XC,TC-1,TT-1));
*);

* Write Demand DDS File
         PUT  SIM_DEM_FILE;
         SIM_DEM_FILE.pc = 2;
         SIM_DEM_FILE.nd = 13;
         SIM_DEM_FILE.ap = 0;

         PUT 'PARAMETER ACOM_PROJ /' /;

         LOOP((DEM1,TTIMES),
                 EFVAL = SIM_DEMX(DEM1,TTIMES);
                 if(EFVAL,
                         PUT "REGION1.", DEM1.TL, ".", TTIMES.TL, EFVAL /;
                 else
                         PUT "REGION1.", DEM1.TL, ".", TTIMES.TL, "eps" /;

                 );
         );
$ontext

         PUT "/;"/;

*Write Cumulative CO2 CAP bound
         PUT 'PARAMETER ACOMCUMNET /' /;
         EFVAL = SIM_CO2CUMUL(RUN)*1000000;
         if(EFVAL,
                 PUT "REGION1.CO2EQSB.2021.2050.'UP'  ", EFVAL /;
         );
$offtext
         PUTCLOSE "/;";

         PUT  ShowRunNumber;
         RUNTIMES2.pc = 2;
         RUNTIMES2.nd = 5;
         RUNTIMES2.ap = 0;
         PUTCLOSE "";

$include GHATIM\includes\2runTIMES.inc
);
* if(SIM_eMOD(RUN) eq 1,

$include GHATIM\includes\2TIMESReport.inc

* adjust capital intensity - still need to add labour intensity
IFAGR(F,A,TC) = SUM(FS$MFSA(FS,A),IFAFSGR(F,FS,TC));
* do reverse mapping for industry sectors (excludes power and petroleum)
ICAGR(CXEP,A,TC) = SUM(FSXEP$MFSA(FSXEP,A),ICAFSGR(CXEP,FSXEP,TC));

  LOOP(TC$(NOT fail),
    IF(NOT T1(TC),

*     Long term TFP growth
      alphava(A,RD) = alphava(A,RD) * (1+TFPGR(A,RD,XC,TC));

*     Long term factor-specific productivity growth
      fprd(F,A,RD)$(NOT AFX(A,RD)) = COVIDCAP(A,F,XC,TC);
*fprd(F,A,RD)*(1+FPRDGR(F,XC,TC));
*COVIDCAP(A,F,XC,TC);

*     World price changes
*      pwebar(C,RW) = pwebar(C,RW) * (1+PWEGR(C,XC,TC));
      PWE.L(C,RW)  = PWE.L(C,RW)  * (1+PWEGR(C,XC,TC));
      PWM.L(C,RW)  = PWM.L(C,RW)  * (1+PWMGR(C,XC,TC));

*     Population growth
      hpop(H) = hpop(H) * (1+POPGR(H,XC,TC));

*adjust ifas
      ifa(F,A,'nat') = ifa(F,A,'nat')*IFAGR(F,A,TC);

* adjust icas
*      if(ord(TC) = 2,
*         ica('cpetr','aelec','NAT') = ica('ccoil','aelec','NAT');
*         ica('ccoil','aelec','NAT') = 0.0001;
*      );

*      if(ord(TC) > 2,
*         ica(C,A,'NAT')$(ICAGR(C,A,TC) and ica0(C,A,'NAT')) = ica(C,A,'NAT')*ICAGR(C,A,TC);
*      );

      if(ord(TC) < 8,
*         ica('cpetr','aelec','NAT') = ica('cpetr','aelec','NAT')*2;
         ica('ccoil','aelec','NAT') = ica('ccoil','aelec','NAT')*0.5;

* adjust elc intensity of mining down to same level as South Africa Gold Mining
         ica('celec','aomin','NAT') = ica('celec','aomin','NAT')*0.92;
      );

      if(ord(TC) > 4,
         ica('cngas','aelec','NAT') = max(0.00001,EIntensity_FS('elec','cngas',TC));
         ica('cpetr','aelec','NAT') = max(0.00001,ica('cpetr','aelec','NAT')*0.5);
      );


* Other Settings
* electricity sector
    AFX('AELEC',RD) = NO;
    AFLEO('AELEC') = NO;
    AFX('AELEC',RD)$EFX(TT,TC) = YES;
    AFLEO('AELEC')$EFX(TT,TC) = YES;

*    AFX('AELEC',RD) = YES;
*    AFLEO('AELEC') = YES;


    AFXGR('aelec','NAT',XC,TC)$EFX(TT,TC) = QFEGY_GR(RUN,TC)- 1;
*    AFXGR('aelec','NAT',XC,TC) = QFEGY_GR(RUN,TC)- 1;

*    WFDIST.FX('fegy','aelec','nat') = 1;


*    CERES('CELEC') = YES;
*    CERES('CELEC')$EFX(TT,TC) = NO;
*    CEFIX('CELEC') = YES;
*    CEFIX('CELEC')$EFX(TT,TC) = NO;
*    QE.FX('CELEC','REST') = QE.L('CELEC','REST');
*    QE.UP('CELEC','REST')$EFX(TT,TC) = Inf;
*    QE.LO('CELEC','REST')$EFX(TT,TC) = -Inf;




*     Exgenous transfer changes
      trnsfr(INS,ACNT) = trnsfr(INS,ACNT) * (1+TRNSFRGR(INS,ACNT,XC,TC));

*     Capital stock accumulation and allocation
$include cge\includes\2capital.inc

*     Labor supply growth
      QF.L(FLAB,A,RD)$(NOT T1(TC)) = QF.L(FLAB,A,RD)*(1+FACGR(FLAB,XC,TC));
*      QF.L('FEGY',A,RD)$(NOT T1(TC)) = QF.L('FEGY',A,RD)*(1+FACGR('FEGY',XC,TC));
      QF.L('FLND',A,RD)$(NOT T1(TC)) = QF.L('FLND',A,RD)*(1+FACGR('FLND',XC,TC));

*     Total factor supply
      QFS.L(F) = SUM((RD,A), QF.L(F,A,RD));

    );
* IF(NOT T1(TC),

$include cge\includes\2closures.inc

 PQ.FX('CELEC') = EPRICE(TC,TT);
* PQ.UP('CELEC')$(not EFX(TT,TC)) = inf;
* PQ.LO('CELEC')$(not EFX(TT,TC)) = -inf;

 TQ.LO('CELEC') = -INF;
 TQ.UP('CELEC') = +INF;




 SOLVE standcge USING MCP ;

$include cge\includes\2results.inc
$include cge\includes\2energychecks.inc
ELCDEM(FSeMOD,TC) = EBCHECK('eGEM',FSeMOD,'IN','celec',TC,TT,RUN)*(-1);

execute_unload "EnergyDemand.gdx" ELCDEM


  );
*end of TC loop
*$include cge\includes\2energyfcast.inc

 );
* end of TT loop

);
* end of XC loop


