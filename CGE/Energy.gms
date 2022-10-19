$SETGLOBAL modeldata    "1model2015GH.xlsx"

$call "gdxxrw i=%modeldata% o=modeldatab.gdx index=index2!a5 checkdate"
$gdxin modeldatab.gdx

SETS
 AC                      global set for model accounts - aggregated microsam accounts
 ACNT(AC)                all elements in AC except TOTAL
 A(AC)                   activities
 H(AC)                   households
;

PARAMETER
 SAM(AC,AC)              standard SAM
 SAMBALCHK(AC)           column minus row total for SAM
 GAS(*,*)                details for gas separation
;

$load AC A H
$loaddc SAM GAS

ALIAS
 (AC,ACP), (ACNT,ACNTP), (A, AP), (H, HP);

 ACNT(AC)               = YES;
 ACNT('TOTAL')          = NO;

*-------------------------------------------------------------------------------
*1. SAM adjustments
*-------------------------------------------------------------------------------
*combine coffee and coco
 SAM('ccoco',ACNT)=SAM('ccoco',ACNT)+SAM('ccoff',ACNT);
 SAM(ACNT,'ccoco')=SAM(ACNT,'ccoco')+SAM(ACNT,'ccoff');

 SAM('acoco',ACNT)=SAM('acoco',ACNT)+SAM('acoff',ACNT);
 SAM(ACNT,'acoco')=SAM(ACNT,'acoco')+SAM(ACNT,'acoff');

 SAM('ccoff',ACNT)=0;
 SAM(ACNT,'ccoff')=0;

 SAM('acoff',ACNT)=0;
 SAM(ACNT,'acoff')=0;

*combine types of capital
*Combining other types of capital
 SAM('fcap',AC)=SAM('fcap-c',AC)+SAM('fcap-l',AC)+SAM('fcap-m',AC)+SAM('fcap-n',AC);
 SAM(AC,'fcap')=SAM(AC,'fcap-c')+SAM(AC,'fcap-l')+SAM(AC,'fcap-m')+SAM(AC,'fcap-n');

 SAM('fcap-c',AC)=0;
 SAM('fcap-l',AC)=0;
 SAM('fcap-m',AC)=0;
 SAM('fcap-n',AC)=0;

 SAM(AC,'fcap-c')=0;
 SAM(AC,'fcap-l')=0;
 SAM(AC,'fcap-m')=0;
 SAM(AC,'fcap-n')=0;

 SAM('TOTAL',AC) = SUM(ACNT, SAM(ACNT,AC));
 SAM(AC,'TOTAL') = SUM(ACNT, SAM(AC,ACNT));
 SAMBALCHK(AC)   = SAM('TOTAL',AC) - SAM(AC,'TOTAL');
*$exit
*-------------------------------------------------------------------------------
*20/09/22
*2. Separarting natural gas and crude oil
*-------------------------------------------------------------------------------
*net exports
Parameter
TEST
;

 SAM('ANGAS','CNGAS')=GAS('PRODUCTION','VALUE');
 SAM('ANGAS','TOTAL')=SAM('ANGAS','CNGAS');

 SAM(ACNT,'ANGAS')=SAM('ANGAS','TOTAL')*(SAM(ACNT,'ACOIL')/SUM(ACNTP,SAM(ACNTP,'ACOIL')));

 SAM('CNGAS','ROW') = 0.000001;
 SAM('CNGAS','AELEC') = GAS('POWER','VALUE')-0.000001;
 SAM('CNGAS','TOTAL') = SUM(ACNT, SAM('CNGAS',ACNT));

 SAM('ROW','CNGAS') = GAS('IMPORTS','VALUE');
* SAM('MTAX','CNGAS')= SAM('MTAX','CCOIL');
* SAM('TRC','CNGAS') = (SAM('TRC','CCOIL')/SAM('TOTAL','CCOIL'))*SAM('CNGAS','TOTAL');

 SAM('ACOIL','CCOIL')=SAM('ACOIL','CCOIL')-SAM('ANGAS','CNGAS');
 SAM(ACNT,'ACOIL')= SAM(ACNT,'ACOIL')- SAM(ACNT,'ANGAS');

 SAM('CCOIL','ROW')  = SAM('CCOIL','ROW')  -SAM('CNGAS','ROW');
 SAM('CCOIL','AELEC')= SAM('CCOIL','AELEC')-SAM('CNGAS','AELEC');

 SAM('ROW' ,'CCOIL') = SAM('ROW' ,'CCOIL')  -  SAM('ROW','CNGAS');
* SAM('MTAX','CCOIL')=  SAM('MTAX','CCOIL') -  SAM('MTAX','CNGAS');
* SAM('TRC' ,'CCOIL') = SAM('TRC' ,'CCOIL')  -  SAM('TRC','CNGAS') ;

 SAM('TOTAL',AC) = SUM(ACNT, SAM(ACNT,AC));
 SAM(AC,'TOTAL') = SUM(ACNT, SAM(AC,ACNT));
 SAMBALCHK(AC)   = SAM('TOTAL',AC) - SAM(AC,'TOTAL');
*$exit
*-------------------------------------------------------------------------------
*3. Adjusting SAM to account for energy volumes
*-------------------------------------------------------------------------------
Sets
 ea
 meaac(ea,ac)
;

Parameter
 xprice(ac)      power price
 ebal(ea)        power use (PJ)
 eval(ea)        expected energy value (energy aggregate)
 eval2(ac)       expected energy value (SAM accounts)
 eval3(*)        expected energy value (SAM accounts) - trade
 eutax(ac)       difference in energy values
;

$load EA MEAAC
$loaddc XPRICE EBAL

*remove power own consumption
 SAM('aelec','celec')=SAM('aelec','celec')-SAM('celec','aelec');
 SAM('celec','aelec')=0;

 SAM('TOTAL',AC) = SUM(ACNT, SAM(ACNT,AC));
 SAM(AC,'TOTAL') = SUM(ACNT, SAM(AC,ACNT));
 SAMBALCHK(AC)   = SAM('TOTAL',AC) - SAM(AC,'TOTAL');
display SAMBALCHK;

*Add in net electricity exports
*SAM currently includes very small volumes which seem incorrect given the energy balance
*1sambal.inc is used to balance the SAM

*Create net imports
 SAM('row','celec')=SAM('row','celec')-SAM('celec','row');
 SAM('celec','row')=0;

 SAM('TOTAL',AC) = SUM(ACNT, SAM(ACNT,AC));
 SAM(AC,'TOTAL') = SUM(ACNT, SAM(AC,ACNT));
 SAMBALCHK(AC)   = SAM('TOTAL',AC) - SAM(AC,'TOTAL');


$ontext
*include new value for exports
* SAM('celec','row')  =  (ebal('exp')-ebal('imp'))*xprice('celec');
 SAM('celec','dstk')=SAM('celec','dstk')+(SAM('row','celec')-SAM('celec','row')+
                         (ebal('imp')-ebal('exp'))*xprice('celec'));
 SAM('row','celec')  =  (ebal('imp')-ebal('exp'))*xprice('celec');
 SAM('celec','row')  = 0;

 SAM('gov','mtax')=SAM('gov','mtax')-SAM('mtax', 'celec');
 SAM('s-i','gov')=SAM('s-i','gov')-SAM('mtax', 'celec');

 SAM('celec','dstk')=SAM('aelec','celec')-sum(ACNT,SAM('celec',ACNT));
 SAM('dstk','s-i')=SAM('dstk','s-i')+SAM('celec','dstk');
 SAM('s-i','row')=SAM('s-i','row')+SAM('celec','dstk')+SAM('mtax', 'celec');

*remove imports
 SAM('row', 'celec')=0;
 SAM('mtax', 'celec')=0;

$include includes/1sambal.inc
$offtext

 SAM('TOTAL',AC) = SUM(ACNT, SAM(ACNT,AC));
 SAM(AC,'TOTAL') = SUM(ACNT, SAM(AC,ACNT));
 SAMBALCHK(AC)   = SAM('TOTAL',AC) - SAM(AC,'TOTAL');
display SAMBALCHK;

 eval(ea)=ebal(ea)*xprice('celec');
 eval2(a)$SAM('celec',a)=sum(ea$meaac(ea,a),eval(ea))*(SAM('celec',a)/sum(ea$meaac(ea,a),sum(ap$meaac(ea,ap),SAM('celec',ap))));
 eval2(h)$SAM('celec',h)=sum(ea$meaac(ea,h),eval(ea))*(SAM('celec',h)/sum(ea$meaac(ea,h),sum(hp$meaac(ea,hp),SAM('celec',hp))));

 eutax(ac)$eval2(ac)=SAM('celec',ac)-eval2(ac);

 SAM('celec',a)=eval2(a);
 SAM('celec',h)=eval2(h);

 SAM('utax',ac)=eutax(ac);

 SAM('ent','utax')=sum(ACNT,SAM('utax',ACNT));

 SAM('TOTAL',AC) = SUM(ACNT, SAM(ACNT,AC));
 SAM(AC,'TOTAL') = SUM(ACNT, SAM(AC,ACNT));
 SAMBALCHK(AC)   = SAM('TOTAL',AC) - SAM(AC,'TOTAL');
display SAMBALCHK;
*$exit
*-------------------------------------------------------------------------------
*2. Capital account for electricity
*-------------------------------------------------------------------------------
*$ontext
 SAM('fegy','aelec')=SAM('fcap','aelec');
 SAM('ent','fegy')=SAM('fegy','aelec');

 SAM('fcap','aelec')=SAM('fcap','aelec')-SAM('fegy','aelec');
 SAM('ent','fcap')=SAM('ent','fcap')-SAM('ent','fegy');
*$offtext

 SAM('TOTAL',AC) = SUM(ACNT, SAM(ACNT,AC));
 SAM(AC,'TOTAL') = SUM(ACNT, SAM(AC,ACNT));
 SAMBALCHK(AC)   = SAM('TOTAL',AC) - SAM(AC,'TOTAL');
*$exit
*-------------------------------------------------------------------------------
*3. Matching petroleum
*-------------------------------------------------------------------------------
Sets
 pea
 mpeaac(pea,ac)
;

Parameter
 pbal(pea)        power use (PJ)
 pval(pea)        expected energy value (energy aggregate)
 pval2(ac)       expected energy value (SAM accounts)
 pval3(*)        expected energy value (SAM accounts) - trade
 putax(ac)       difference in energy values
;

$load PEA MPEAAC
$loaddc PBAL
*create net imports

 SAM('row','cpetr')=SAM('row','cpetr')-SAM('cpetr','row');
 SAM('cpetr','row')=0;

 SAM('TOTAL',AC) = SUM(ACNT, SAM(ACNT,AC));
 SAM(AC,'TOTAL') = SUM(ACNT, SAM(AC,ACNT));
 SAMBALCHK(AC)   = SAM('TOTAL',AC) - SAM(AC,'TOTAL');
display SAMBALCHK;

 pval(pea)=pbal(pea)*xprice('cpetr');
 pval2(a)$SAM('cpetr',a)=sum(pea$mpeaac(pea,a),pval(pea))*(SAM('cpetr',a)/sum(pea$mpeaac(pea,a),sum(ap$mpeaac(pea,ap),SAM('cpetr',ap))));
 pval2(h)$SAM('cpetr',h)=sum(pea$mpeaac(pea,h),pval(pea))*(SAM('cpetr',h)/sum(pea$mpeaac(pea,h),sum(hp$mpeaac(pea,hp),SAM('cpetr',hp))));

 putax(ac)$pval2(ac)=SAM('cpetr',ac)-pval2(ac);

 SAM('cpetr',a)=pval2(a);
 SAM('cpetr',h)=pval2(h);

 SAM('ptax',ac)=putax(ac);

 SAM('ent','ptax')=sum(ACNT,SAM('ptax',ACNT));

 SAM('TOTAL',AC) = SUM(ACNT, SAM(ACNT,AC));
 SAM(AC,'TOTAL') = SUM(ACNT, SAM(AC,ACNT));
 SAMBALCHK(AC)   = SAM('TOTAL',AC) - SAM(AC,'TOTAL');
display SAMBALCHK;
*$exit
 execute_unload "boom.gdx" SAM;
 execute 'gdxxrw.exe i=boom.gdx o=%modeldata% index=index2!a80';
