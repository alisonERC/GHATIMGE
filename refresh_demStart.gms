* This code is used to refresh the demstart.gdx file with values sitting in the Drivers.xlsm workbook
* This file is kept to ensure that all runs are initialised with the same demand.
* dem_start should be refreshed everytime there is a large departure in growth assumptions
* to speed up convergence

sets
AY years /2015*2070/
FSeMOD sectors
C Commodities
MOD models /eMOD,eGEM/
TC(AY)
TT(AY)
RUN
IN_OUT /IN,OUT/;

parameters
EBCHECK(MOD,FSeMOD,IN_OUT,C,TC,TT,RUN)
ELCDEM(FSeMOD,TC)
;
$gdxin  TestGHATIM8.gdx
$load FSeMOD, C, TC, TT, RUN, EBCHECK
ELCDEM(FSeMOD,TC) = EBCHECK('eGEM',FSeMOD,'IN','celec',TC,'2050','Reference')*(-1);

execute_unload "dem_start.gdx" ELCDEM
