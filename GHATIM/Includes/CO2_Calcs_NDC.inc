* Code to calculate CO2 for eMOD (and eSAGE) given eMOD_OUTPUT and INTX and QHX
$SETGLOBAL referencerun REF_EV-IN_RB-ZERO

Sets
  RUN                            simulations
  INCLRUN(RUN)                        whether to include or not run in batch
*  GDXFile                        GDX file per simulation /NoLink_EV-IN, REF_EV-IN_RB-ZERO,REF_EV-IN_RB-0-25,REF_EV-IN_RB-0-5,REF_EV-OUT_RB-ZERO,REF_EV-OUT_RB-0-25,REF_EV-OUT_RB-0-5 /
  GDXFile                        GDX file per simulation /CalibRefSIC/
*, CalibReFSeMOD/
  MGDXRUN(GDXFile,RUN)           Map of RUN and GDX file
* eMOD sets
  REG                            TIMES regions    /REGION1/
  ALLYEAR                        All Years
  T(ALLYEAR)                     Time periods
  V(ALLYEAR)                     Vintage
  S                              TIMES timeslices
  PRC                            TIMES Processes
  P(PRC)                         Processes
  COM                            TIMES Commodities
  X                       simulations
  XC(X)                   active simulations
  TC(T)                   active time periods
*Times model sets
  TT(T)                   TIMES model years
  IN_OUT flow direction /IN, OUT/
  eMOD_IND /Activity, Capacity, NewCapacity, FlowIn, FlowOut, CO2, CH4, N2O, CO2eq, Investment, GVA, Employment/
  HH_EI Household Energy Indicators
  C                   commodities
  H               households
  MOD models /eMOD, eSAGE/
  Emiss(eMOD_IND) / CO2, CH4, N2O, CO2eq/
  FS                      eMOD sectors
  MPRCFS(PRC,FS)            mapping eMOD PRCs to eMOD sectors
  MFSP(FS,PRC)           mapping of technologies used for each sector to track process emissions
;

Parameters
  eMOD_OUTPUT(PRC,COM,T,eMOD_IND,RUN) eMOD indicators by run and activity
  eMOD_OUTPUT2(PRC,COM,T,eMOD_IND,GDXFile) eMOD indicators by run and activity
  HH_Energy(MOD,HH_EI,C,T,RUN) Household energy consumption
  HH_Energy2(MOD,HH_EI,C,T,GDXFile) Household energy consumption
  QHX(C,H,X,T,TT)                  qnty consumed of market commodity c by household h

  EmisFactor(COM,Emiss) Combustion Emission Factor

  ProcessEmissions(FS,T,Emiss,GDXFILE) Process emissions
;

$gdxin  %referencerun%.gdx
$load PRC P COM ALLYEAR S V T X XC TC TT RUN HH_EI H C FS MPRCFS

$call   "gdxxrw i=EmissionFactors.xlsx o=EmisFac index=Index!a6 checkdate"
$gdxin  EmisFac.gdx
$load EmisFactor

MGDXRUN('CalibRefSIC','REF2019-UCE-L') = YES;
*MGDXRUN('CalibRefSIC','REF2019-UCE-L') = YES;

*MGDXRUN('REF_EV-IN_RB-ZERO','REF2019-UCE-L') = YES;
*MGDXRUN('REF_EV-IN_RB-0-25','REF2019-UCE-L') = YES;
*MGDXRUN('REF_EV-IN_RB-0-5','REF2019-UCE-L') = YES;
*MGDXRUN('REF_EV-OUT_RB-ZERO','TRAPES-UCE-L') = YES;
*MGDXRUN('REF_EV-OUT_RB-0-25','TRAPES-UCE-L') = YES;
*MGDXRUN('REF_EV-OUT_RB-0-5','TRAPES-UCE-L') = YES;

* chemicals sector
MFSP('cp','XICPGAS') = yes;
* non metallic minerals (cement, lime and glass)
MFSP('nm','XINMGAS') = yes;
* non ferous (aluminium, lead and zinc)
MFSP('nf','XINFGAS') = yes;
* iron and steel
MFSP('is','XIISGAS') = yes;
* ferro-alloys
* 'fa' not defined yet need to do so.
*MFSP('fa','XIFAGAS') = yes;
* non-energy 2D, and product use 2F assigned to "industry other", although the emission should take place
* in the commercial sector in eMOD, as the dominant emission out of this lot is 2F1-refrigerant-air-conditioning.
MFSP('COM','XIOTGAS') = yes;



FILE eMOD_Scen;

LOOP(GDXFile,

put_utilities eMOD_Scen 'gdxin' / GDXFile.TL:20;

execute_load eMOD_OUTPUT HH_Energy;
Loop(RUN,
eMOD_OUTPUT2(PRC,COM,TC,eMOD_IND,GDXFile)$MGDXRUN(GDXFile,RUN) = eMOD_OUTPUT(PRC,COM,TC,eMOD_IND,RUN);
HH_Energy2(MOD,HH_EI,C,TC,GDXFile)$MGDXRUN(GDXFile,RUN) = HH_Energy(MOD,HH_EI,C,TC,RUN);
);


eMOD_OUTPUT2(PRC,COM,TC,Emiss,GDXFile) = eMOD_OUTPUT2(PRC,COM,TC,'FlowIn',GDXFile)*EmisFactor(Com,Emiss);

* convert energy flows to TJ to match inventory and DOE energy balances
eMOD_OUTPUT2(PRC,COM,TC,'Flowin',GDXFile) = eMOD_OUTPUT2(PRC,COM,TC,'FlowIn',GDXFile)*1000;

* Refinery sector Combustion emissions 1A
eMOD_OUTPUT2(PRC,'ACTGRP',TC,'CO2',GDXFile) = eMOD_OUTPUT2(PRC,'UPSCO2S',TC,'FlowOut',GDXFile);
eMOD_OUTPUT2(PRC,'ACTGRP',TC,'CH4',GDXFile) = eMOD_OUTPUT2(PRC,'UPSCH4S',TC,'FlowOut',GDXFile);

* Mining 1B1 Fugitive Emissions
*eMOD_OUTPUT2('XUPSCLE','ACTGRP',TC,'CO2',GDXFile) = sum(PRC$MPRCFS(PRC,'coal'),eMOD_OUTPUT2(PRC,'CO2SF',TC,'FlowOut',GDXFile));
*eMOD_OUTPUT2('XUPSCLE','ACTGRP',TC,'CH4',GDXFile) = sum(PRC$MPRCFS(PRC,'coal'),eMOD_OUTPUT2(PRC,'CH4SF',TC,'FlowOut',GDXFile));
eMOD_OUTPUT2(PRC,'ACTGRP',TC,'CO2',GDXFile)$MPRCFS(PRC,'coal') = eMOD_OUTPUT2(PRC,'CO2SF',TC,'FlowOut',GDXFile));
eMOD_OUTPUT2(PRC,'ACTGRP',TC,'CH4',GDXFile)$MPRCFS(PRC,'coal') = eMOD_OUTPUT2(PRC,'CH4SF',TC,'FlowOut',GDXFile));




* CTL 1B3 Fugitive emissions
eMOD_OUTPUT2('UTRNGIMGAS','ACTGRP',TC,'CO2',GDXFile) = eMOD_OUTPUT2('UCTLCLEIN-E','CO2SF',TC,'FlowOut',GDXFile);
eMOD_OUTPUT2('UTRNGIMGAS','ACTGRP',TC,'CH4',GDXFile) = eMOD_OUTPUT2('UCTLCLEIN-E','CH4SF',TC,'FlowOut',GDXFile);

* GTL 1B3 emissions

* Gas 1B2 Fugitive Emissions = the rest of fugitive emissions happening all over the place (gas network)
eMOD_OUTPUT2('XUPSGAS','ACTGRP',TC,'CH4',GDXFile) = sum(PRC,eMOD_OUTPUT2(PRC,'CH4SF',TC,'FlowOut',GDXFile))
                                                     -eMOD_OUTPUT2('XUPSCLE','ACTGRP',TC,'CH4',GDXFile)
                                                     -eMOD_OUTPUT2('UTRNGIMGAS','ACTGRP',TC,'CH4',GDXFile);

* Process emissions
ProcessEmissions(FS,TC,'CO2',GDXFILE) = sum(PRC$MPRCFS(PRC,FS),eMOD_OUTPUT2(PRC,'CO2SP',TC,'FlowOut',GDXFile));
*ProcessEmissions(FS,TC,'CH4',GDXFILE) = sum(PRC$MPRCFS(PRC,FS),eMOD_OUTPUT2(PRC,'CH4SP',TC,'FlowOut',GDXFile));
*ProcessEmissions(FS,TC,'N2O',GDXFILE) = sum(PRC$MPRCFS(PRC,FS),eMOD_OUTPUT2(PRC,'N2OSP',TC,'FlowOut',GDXFile));

loop(FS,
*eMOD_OUTPUT2(PRC,COM,TC,Emiss,GDXFile)$MFSP(FS,PRC) = 0;
eMOD_OUTPUT2(PRC,'ACTGRP',TC,Emiss,GDXFile)$MFSP(FS,PRC) = ProcessEmissions(FS,TC,Emiss,GDXFile);
);

);

execute_unload "eMOD_OUTPUT.gdx" eMOD_OUTPUT2
execute 'gdxxrw.exe i=eMOD_OUTPUT.gdx o=.\Emissions_Calibration\GHATIM_OUTPUT.xlsx index=index!a6';

*execute_unload "HH_En.gdx" HH_Energy2
*execute 'gdxxrw.exe i=HH_En.gdx o=C:\GHATIMGE_03\Emissions_Calibration\Private_Transport_Results_v00.xlsx index=index!a6';

