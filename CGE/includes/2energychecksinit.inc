sets
  MOD models /eMOD, eGEM/
  QType quantitity types /qq, qd, qint, qe, qm, qh, qx, qxac/
  IN_OUT flow direction /IN, OUT, CO2/
  eMOD_IND eMOD indicators /Activity, Capacity, NewCapacity, FlowIn, FlowOut, CO2, Investment, GVA, Employment/
  CGE_IND /GVA, Employment/

  eMOD_LAB(UC_N) eMOD employment constraint names / UCPWR_FLAB-RN, UCPWR_FLAB-RP, UCPWR_FLAB-RS, UCPWR_FLAB-RT, UCPWR_FLAB-UN, UCPWR_FLAB-UP, UCPWR_FLAB-US, UCPWR_FLAB-UT/

  HH_EI Household Energy Indicators /TRA, OTH/

;

parameters
 BalanceCheck(QType,C,TC,RUN) balance check

 EBCHECK(MOD,FSeMOD,IN_OUT,C,TC,TT,RUN) Final Energy Demand for eMOD sectors in eMOD and eGEM models

 EIntensity(MOD,FSeMOD,C,TC,TT,RUN) Energy Intensity in eMOD and EGEM models

 CO2OUT(C) CO2 emission factors for linked model

 CGE_OUTPUT(A,TC,CGE_IND,RUN) CGE indicators by run and activity

 eMOD_OUTPUT(PRC,COM,TC,eMOD_IND,RUN) eMOD indicators by run and activity

 HH_Energy(MOD,HH_EI,C,TC,RUN) Household energy consumption
;

$ontext
*FSM
 CO2OUT('ccoal-low') = 96.25;
 CO2OUT('ccoal-hgh') = 96.25;
 CO2OUT('cngas') = 56.1;
 CO2OUT('cpetr-p') = 69.3;
 CO2OUT('cpetr-d') = 74.0667;
 CO2OUT('cpetr-h') = 77.4;
 CO2OUT('cpetr-k') = 72.9;
 CO2OUT('cpetr-l') = 63.1;
$offtext

