SET
 SAC             SAM account categories  /
  ACT            activities
  COM            commodities
  FAC            factors
  INSDNG         domestic non-government institutions
  GOV            government
  SAVINV         savings-investments
  INSTAX         direct taxes on institutions
  FACTAX         direct taxes on factors
  VATAX          value added tax
  ACTTAX         tax on activity gross revenue
  COMTAX         tax on commodity sales in the domestic market
  IMPTAX         import tariff
  EXPTAX         export tax
  ROW            rest of world (FCU)
 /
 KGDP            first index in GDP tables  /
  NOMINAL, REAL, NOMSHARE, REALSHARE, DEFLATOR
 /
 KGDP2(KGDP)     Non shares for growth rates /
  NOMINAL, REAL, DEFLATOR
 /
 IGDP            Items for GDP and national accounts  /
  ABSORP         absorption
  PRVCON         private consumption
  FIXINV         fixed investment
  DSTOCK         stock change
  GOVCON         government consumption
  EXPORTS        exports
  IMPORTS        imports
  GDPMP          GDP at market prices (alt. 1: spending)
  GDPMP2         GDP at market prices (alt. 2: value-added)
  NETITAX        net indirect taxes
  GDPFC2         GDP at factor cost
 /
 IGDP2(IGDP)     Items for GDPMP summation  /
  PRVCON         private consumption
  FIXINV         fixed investment
  DSTOCK         stock change
  GOVCON         government consumption
  EXPORTS        exports
  IMPORTS        imports
 /
 MODTYPE         model types  /
  MCP            mixed-complementarity programming
  NLP            non-linear programming
 /
 SIND            Macro summary indicators /
  QABSTOT        real absorption (LCU at base prices)
  QHTOT          real household consumption (LCU at base prices)
  QINVTOT        real investment (LCU at base prices)
  QGTOT          real government consumption (LCU at base prices)
  QETOT          total real exports (LCU at base prices)
  QMTOT          total real imports (LCU at base prices)
  REXR           PPP real exchange rate (LCUs per FCU)
  NEXR           nominal exchange rate (LCUs per FCU)
  PWEIND         exports price index (FCU -- 100 for base)
  PWMIND         imports price index (FCU -- 100 for base)
  PWIND          world (tradables) price index (FCU -- 100 for base)
  PDIND          domestic (non-tradables) price index (100 for base)
  CPI            consumer price index (100 for base)
  TOFT           terms of trade (ratio pwe index & pwm index) (100 for base)
  INVGDP         investment (% of nominal GDP)
  PRVSAVGDP      private (household + enterprise) savings (% of nominal GDP)
  FORSAVGDP      foreign savings (% of nominal GDP)
  TRDDEFGDP      trade deficit (% of nominal GDP)
  GOVSAVGDP      government savings (% of nominal GDP)
  IMPTAXGDP      tariff revenue (% of nominal GDP)
  DIRTAXGDP      direct tax revenue (% of nominal GDP)
 /
 SINDDEV(SIND)   summary indicators showing deviation from BASE /
  INVGDP         investment (% of nominal GDP)
  PRVSAVGDP      private (household + enterprise) savings (% of nominal GDP)
  FORSAVGDP      foreign savings (% of nominal GDP)
  TRDDEFGDP      trade deficit  (% of nominal GDP)
  GOVSAVGDP      government savings (% of nominal GDP)
  IMPTAXGDP      import tax revenue (% of nominal GDP)
  DIRTAXGDP      direct tax revenue (% of nominal GDP)
 /
 SINDGR(SIND) /
  QABSTOT        real absorption (LCU at base prices)
  QHTOT          real household consumption (LCU at base prices)
  QINVTOT        real investment (LCU at base prices)
  QGTOT          real government consumption (LCU at base prices)
  QETOT          total real exports (LCU at base prices)
  QMTOT          total real imports (LCU at base prices)
 /
 SINDP(SIND)     summary indicators showing percent change
;

 SINDP(SIND)$(NOT SINDDEV(SIND)) = YES;

PARAMETERS
 pdwt(C)                       weight of commodity c in PD index
 pwewt(C,RW)                   weight of commodity c in pwe index
 pwmwt(C,RW)                   weight of commodity c in pwm index
 pwwt(*)                       weight of aggregate exports-imports in pw (tradables) index
 IC(H,X)                       indirect compensation fn by hhd h and Xulation X
 EV(H,X)                       equivalent variation by hhd h and Xulation X
 MACROTAB(SIND,X)              macro table (whole period changes)
 MACROTABX(SIND,X,T)           macro table data
 MACROTABXA(SIND,X)            macro table (average annual changes)
 MACROTABXY(SIND,X,T)          macro table (year-on-year changes)
 QHTAB(AC,X)                   disaggregated real household consumption
 EVTAB(AC,X)                   disaggregated EV
 YFTAB(AC,X)                   disaggregated factor income distribution
 QATAB(AC,X)                   disaggregated activity production levels
 PATAB(AC,X)                   disaggregated activity prices
 QHTABA(AC,X)                  disaggregated real household consumption
 EVTABA(AC,X)                  disaggregated EV
 YFTABA(AC,X)                  factor distribution
 QATABA(AC,X)                  disaggregated activity production levels
 PATABA(AC,X)                  disaggregated activity prices

 ALPHAVAXY(A,RD,X,T)           productivity parameter in production function
 CPIXY(X,T)                    consumer price index (PQ-based)
 DPIXY(X,T)                    index for domestic producer prices (PDS-based)
 DMPSXY(X,T)                   change in maRDinal propensity to save for selected inst
 DTINSXY(X,T)                  change in domestic institution tax share
 EGXY(X,T)                     total current government expenditure
 EHXY(H,X,T)                   household consumption expenditure
 EXRXY(X,T)                    exchange rate
 FSAVXY(X,T)                   foreign savings
 GADJXY(X,T)                   government demand scaling factor
 GOVSHRXY(X,T)                 govt consumption share of absorption
 GSAVXY(X,T)                   government savings
 HPOPXY(H,X,T)                 household population growth
 IADJXY(IT,X,T)                investment scaling factor (for fixed capital formation)
 INVSHRXY(X,T)                 investment share of absorption
 MPSXY(INS,X,T)                maRDinal propensity to save for dom non-gov inst ins
 MPSADJXY(X,T)                 savings rate scaling factor
 PAXY(A,X,T)                   output price of activity a
 PARXY(A,RD,X,T)               output price of activity a
 PDDXY(C,X,T)                  demand price for com'y c produced & sold domestically
 PDSXY(C,X,T)                  supply price for com'y c produced & sold domestically
 PEXY(C,RW,X,T)                price of exports
 PINTAXY(A,RD,X,T)             price of intermediate aggregate
 PMXY(C,RW,X,T)                price of imports
 PQXY(C,X,T)                   price of composite good c
 PVAXY(A,RD,X,T)               value added price
 PWEXY(C,RW,X,T)               world price of exports
 PWMXY(C,RW,X,T)               world price of imports
 PXXY(C,X,T)                   average output price
 PXACXY(A,C,X,T)               price of commodity c from activity a
 QAXY(A,X,T)                   level of domestic activity
 QARXY(A,RD,X,T)               level of domestic activity
 QDXY(C,X,T)                   qnty of domestic sales
 QEXY(C,RW,X,T)                qnty of exports
 QFXY(F,A,RD,X,T)              qnty demanded of factor f from activity a
 QFSXY(F,X,T)                  qnty of factor supply
 QGXY(C,X,T)                   qnty of government consumption
 QHXY(C,H,X,T)                 qnty consumed of market commodity c by household h
 QHAXY(A,H,X,T)                qnty consumed of home commodity c fr act a by hhd h
 QINTXY(C,A,X,T)               qnty of intermediate demand for c from activity a
 QINTAXY(A,RD,X,T)             qnty of aggregate intermediate input
 QINVXY(C,IT,X,T)              qnty of fixed investment demand
 QMXY(C,RW,X,T)                qnty of imports
 QQXY(C,X,T)                   qnty of composite goods supply
 QTXY(C,X,T)                   qnty of trade and transport demand for commodity c
 QVAXY(A,RD,X,T)               qnty of aggregate value added
 QXXY(C,X,T)                   qnty of aggregate marketed commodity output
 QXACXY(A,C,X,T)               qnty of ouput of commodity c from activity a
 TABSXY(X,T)                   total absorption
 TINSXY(INS,X,T)               rate of direct tax on domestic institutions ins
 TINSADJXY(X,T)                direct tax scaling factor
 TAXY(A,RD,X,T)                activity tax rate
 TMXY(C,RW,X,T)                import tariff rate
 TQXY(C,X,T)                   indirect sales tax rate
 TRIIXY(INS,INSP,X,T)          transfers to dom. inst. insdng from insdngp
 WFXY(F,X,T)                   economy-wide wage (rent) for factor f
 WFDISTXY(F,A,RD,X,T)          factor wage distortion variable
 YFXY(F,X,T)                   factor income
 YGXY(X,T)                     total current government income
 YIFXY(INS,F,X,T)              income of institution ins from factor f
 YIXY(INS,X,T)                 income of (domestic non-governmental) institution ins

 ALPHAVAXA(A,RD,X)             productivity parameter in production function
 CPIXA(X)                      consumer price index (PQ-based)
 DPIXA(X)                      index for domestic producer prices (PDS-based)
 DMPSXA(X)                     change in maRDinal propensity to save for selected inst
 DTINSXA(X)                    change in domestic institution tax share
 EGXA(X)                       total current government expenditure
 EHXA(H,X)                     household consumption expenditure
 EXRXA(X)                      exchange rate
 FSAVXA(X)                     foreign savings
 GADJXA(X)                     government demand scaling factor
 GOVSHRXA(X)                   govt consumption share of absorption
 GSAVXA(X)                     government savings
 HPOPXA(H,X)                   household population growth
 IADJXA(IT,X)                  investment scaling factor (for fixed capital formation)
 INVSHRXA(X)                   investment share of absorption
 MPSXA(INS,X)                  maRDinal propensity to save for dom non-gov inst ins
 MPSADJXA(X)                   savings rate scaling factor
 PAXA(A,X)                     output price of activity a
 PARXA(A,RD,X)                 output price of activity a
 PDDXA(C,X)                    demand price for com'y c produced & sold domestically
 PDSXA(C,X)                    supply price for com'y c produced & sold domestically
 PEXA(C,RW,X)                  price of exports
 PINTAXA(A,RD,X)               price of intermediate aggregate
 PMXA(C,RW,X)                  price of imports
 PQXA(C,X)                     price of composite good c
 PVAXA(A,RD,X)                 value added price
 PWEXA(C,RW,X)                 world price of exports
 PWMXA(C,RW,X)                 world price of imports
 PXXA(C,X)                     average output price
 PXACXA(A,C,X)                 price of commodity c from activity a
 QAXA(A,X)                     level of domestic activity
 QARXA(A,RD,X)                 level of domestic activity
 QDXA(C,X)                     qnty of domestic sales
 QEXA(C,RW,X)                  qnty of exports
 QFXA(F,A,RD,X)                qnty demanded of factor f from activity a
 QFSXA(F,X)                    qnty of factor supply
 QGXA(C,X)                     qnty of government consumption
 QHXA(C,H,X)                   qnty consumed of market commodity c by household h
 QHAXA(A,H,X)                  qnty consumed of home commodity c fr act a by hhd h
 QINTXA(C,A,X)                 qnty of intermediate demand for c from activity a
 QINTAXA(A,RD,X)               qnty of aggregate intermediate input
 QINVXA(C,IT,X)                qnty of fixed investment demand
 QMXA(C,RW,X)                  qnty of imports
 QQXA(C,X)                     qnty of composite goods supply
 QTXA(C,X)                     qnty of trade and transport demand for commodity c
 QVAXA(A,RD,X)                 qnty of aggregate value added
 QXXA(C,X)                     qnty of aggregate marketed commodity output
 QXACXA(A,C,X)                 qnty of ouput of commodity c from activity a
 TABSXA(X)                     total absorption
 TINSXA(INS,X)                 rate of direct tax on domestic institutions ins
 TINSADJXA(X)                  direct tax scaling factor
 TAXA(A,RD,X)                  activity tax rate
 TMXA(C,RW,X)                  import tariff rate
 TQXA(C,X)                     indirect sales tax rate
 TRIIXA(INS,INSP,X)            transfers to dom. inst. insdng from insdngp
 WFXA(F,X)                     economy-wide wage (rent) for factor f
 WFDISTXA(F,A,RD,X)            factor wage distortion variable
 YFXA(F,X)                     factor income
 YGXA(X)                       total current government income
 YIFXA(INS,F,X)                income of institution ins from factor f
 YIXA(INS,X)                   income of (domestic non-governmental) institution ins
 trnsfrxy(INS,AC,X,T)
 trnsfrxa(INS,AC,X)

 GDPTAB1(KGDP,IGDP,X,T)        GDP and national accounts
 GDPTAB2(KGDP,AC,X,T)          GDP at factor cost by activity
 GDPGAP(X,T)                   gaps in GDP reports

 NEGPWARN(C,X,T)               comm c has one or more neg'e prices for sim'on sim
 NEGQWARN(C,X,T)               comm c has one or more neg'e qnties for sim'on sim
 NEGWFWARN(F,X,T)              factor f has one or more neg'e wages for sim'on sim
 NEGQFWARN(F,X,T)              factor f has one or more neg'e qnties for sim'on sim
 GAPWARN(X,T)                  error if abs gap above cutoff
 GAPWARNING(X,T)               error message if abs gap above limit
 WALRASWARN(X,T)               error if abs value of WALRAS above cutoff
;


 GDPTAB1('NOMINAL','PRVCON',XC,TC)   = SUM((C,H), PQX(C,XC,TC)*QHX(C,H,XC,TC))
                                     + SUM((A,H), PAX(A,XC,TC)*QHAX(A,H,XC,TC));
 GDPTAB1('REAL','PRVCON',XC,TC)      = SUM((C,H), PQ0(C)*QHX(C,H,XC,TC))
                                     + SUM((A,H), PA0(A)*QHAX(A,H,XC,TC));
 GDPTAB1('NOMINAL','FIXINV',XC,TC)   = SUM((C,IT), PQX(C,XC,TC)*QINVX(C,IT,XC,TC));
 GDPTAB1('REAL','FIXINV',XC,TC)      = SUM((C,IT), PQ0(C)*QINVX(C,IT,XC,TC));
 GDPTAB1('NOMINAL','DSTOCK',XC,TC)   = SUM(C, PQX(C,XC,TC)*qdst(C));
 GDPTAB1('REAL','DSTOCK',XC,TC)      = SUM(C, PQ0(C)*qdst(C));
 GDPTAB1('NOMINAL','GOVCON',XC,TC)   = SUM(C, PQX(C,XC,TC)*QGX(C,XC,TC));
 GDPTAB1('REAL','GOVCON',XC,TC)      = SUM(C, PQ0(C)*QGX(C,XC,TC));
 GDPTAB1('NOMINAL','EXPORTS',XC,TC)  = SUM((RW,CE), PWEX(CE,RW,XC,TC)*EXRX(XC,TC)*QEX(CE,RW,XC,TC));
 GDPTAB1('REAL','EXPORTS',XC,TC)     = SUM((RW,CE), PWE0(CE,RW)*EXR0*QEX(CE,RW,XC,TC));
 GDPTAB1('NOMINAL','IMPORTS',XC,TC)  = -SUM((RW,CM), PWMX(CM,RW,XC,TC)*EXRX(XC,TC)*QMX(CM,RW,XC,TC));
 GDPTAB1('REAL','IMPORTS',XC,TC)     = -SUM((RW,CM), pwm0(CM,RW)*EXR0*QMX(CM,RW,XC,TC));

 GDPTAB1('NOMINAL','GDPMP',XC,TC)    = SUM(IGDP2, GDPTAB1('NOMINAL',IGDP2,XC,TC));
 GDPTAB1('REAL','GDPMP',XC,TC)       = SUM(IGDP2, GDPTAB1('REAL',IGDP2,XC,TC));
 GDPTAB1('NOMINAL','ABSORP',XC,TC)   = GDPTAB1('NOMINAL','GDPMP',XC,TC) - GDPTAB1('NOMINAL','IMPORTS',XC,TC) - GDPTAB1('NOMINAL','EXPORTS',XC,TC);
 GDPTAB1('REAL','ABSORP',XC,TC)      = GDPTAB1('REAL','GDPMP',XC,TC) - GDPTAB1('REAL','IMPORTS',XC,TC) - GDPTAB1('REAL','EXPORTS',XC,TC);

 GDPTAB1('NOMINAL','GDPFC2',XC,TC)   = SUM((RD,A), PVAX(A,RD,XC,TC)*(1-tva(A,RD))*QVAX(A,RD,XC,TC));
 GDPTAB1('REAL','GDPFC2',XC,TC)      = SUM((RD,A), PVA0(A,RD)*(1-tva0(A,RD))*QVAX(A,RD,XC,TC));

 GDPTAB1('NOMINAL','NETITAX',XC,TC)
         = SUM((RD,A), TAX(A,RD,XC,TC)*PARX(A,RD,XC,TC)*QARX(A,RD,XC,TC))
         + SUM((A,RD), tva(A,RD)*PVAX(A,RD,XC,TC)*QVAX(A,RD,XC,TC))
         + SUM((RW,CM), TMX(CM,RW,XC,TC)*QMX(CM,RW,XC,TC)*PWMX(CM,RW,XC,TC))*EXRX(XC,TC)
         + SUM((RW,CE), te(CE,RW)*QEX(CE,RW,XC,TC)*PWEX(CE,RW,XC,TC))*EXRX(XC,TC)
         + SUM(C, TQX(C,XC,TC)*PQX(C,XC,TC)*QQX(C,XC,TC))
         ;

 GDPTAB1('REAL','NETITAX',XC,TC)
         = SUM((RD,A), ta0(A,RD)*PAR0(A,RD)*QARX(A,RD,XC,TC))
         + SUM((A,RD), tva0(A,RD)*PVA0(A,RD)*QVAX(A,RD,XC,TC))
         + SUM((RW,CM), tm0(CM,RW)*QMX(CM,RW,XC,TC)*PWM0(CM,RW))*EXR0
         + SUM((RW,CE), te0(CE,RW)*QEX(CE,RW,XC,TC)*PWE0(CE,RW))*EXR0
         + SUM(C, tq0(C)*PQ0(C)*QQX(C,XC,TC))
         ;

 GDPTAB1('NOMINAL','GDPMP2',XC,TC)            = GDPTAB1('NOMINAL','GDPFC2',XC,TC) + GDPTAB1('NOMINAL','NETITAX',XC,TC);
 GDPTAB1('REAL','GDPMP2',XC,TC)               = GDPTAB1('REAL','GDPFC2',XC,TC) + GDPTAB1('REAL','NETITAX',XC,TC);
 GDPTAB1('NOMSHARE',IGDP,XC,TC)$GDPTAB1('NOMINAL','GDPMP',XC,TC) = 100*GDPTAB1('NOMINAL',IGDP,XC,TC)/GDPTAB1('NOMINAL','GDPMP',XC,TC);
 GDPTAB1('REALSHARE',IGDP,XC,TC)$GDPTAB1('REAL','GDPMP',XC,TC)  = 100*GDPTAB1('REAL',IGDP,XC,TC)/GDPTAB1('REAL','GDPMP',XC,TC);
 GDPTAB1('DEFLATOR',IGDP,XC,TC)$GDPTAB1('REAL',IGDP,XC,TC) = 100*GDPTAB1('NOMINAL',IGDP,XC,TC)/GDPTAB1('REAL',IGDP,XC,TC);

 GDPTAB2('NOMINAL',A,XC,TC)                   = SUM(RD, PVAX(A,RD,XC,TC)*(1-tva(A,RD))*QVAX(A,RD,XC,TC));
 GDPTAB2('REAL',A,XC,TC)                      = SUM(RD, PVA0(A,RD)*(1-tva0(A,RD))*QVAX(A,RD,XC,TC));

 GDPTAB2('NOMINAL','TOTAL',XC,TC)             = SUM(A, GDPTAB2('NOMINAL',A,XC,TC));
 GDPTAB2('REAL','TOTAL',XC,TC)                = SUM(A, GDPTAB2('REAL',A,XC,TC));
 GDPTAB2('NOMSHARE',A,XC,TC)$GDPTAB2('NOMINAL','TOTAL',XC,TC) = 100*GDPTAB2('NOMINAL',A,XC,TC)/GDPTAB2('NOMINAL','TOTAL',XC,TC);
 GDPTAB2('REALSHARE',A,XC,TC)$GDPTAB2('REAL','TOTAL',XC,TC)   = 100*GDPTAB2('REAL',A,XC,TC)/GDPTAB2('REAL','TOTAL',XC,TC);
 GDPTAB2('NOMSHARE','TOTAL',XC,TC)            = SUM(A, GDPTAB2('NOMSHARE',A,XC,TC));
 GDPTAB2('REALSHARE','TOTAL',XC,TC)           = SUM(A, GDPTAB2('REALSHARE',A,XC,TC));
 GDPTAB2('DEFLATOR',A,XC,TC)$GDPTAB2('REAL',A,XC,TC) = 100*GDPTAB2('NOMINAL',A,XC,TC)/GDPTAB2('REAL',A,XC,TC);
 GDPTAB2('DEFLATOR','TOTAL',XC,TC)$GDPTAB2('REAL','TOTAL',XC,TC) = 100*GDPTAB2('NOMINAL','TOTAL',XC,TC)/GDPTAB2('REAL','TOTAL',XC,TC);

 GDPGAP(XC,TC)                = ABS(GDPTAB1('NOMINAL','GDPMP',XC,TC) - GDPTAB1('NOMINAL','GDPMP2',XC,TC));
 GDPGAP(XC,TC)$(ABS(GDPGAP(XC,TC)) lt 1e-6)  = 0 ;


*Year-on-year percentage changes ------------------------------

 ALPHAVAXY(A,RD,XC,TC)$((NOT T1(TC))   AND ALPHAVAX(A,RD,XC,TC-1))    = (ALPHAVAX(A,RD,XC,TC)   / ALPHAVAX(A,RD,XC,TC-1)-1)*100;
 CPIXY(XC,TC)$((NOT T1(TC))            AND CPIX(XC,TC-1))             = (CPIX(XC,TC)            / CPIX(XC,TC-1)-1)*100;
 DPIXY(XC,TC)$((NOT T1(TC))            AND DPIX(XC,TC-1))             = (DPIX(XC,TC)            / DPIX(XC,TC-1)-1)*100;
 DMPSXY(XC,TC)$((NOT T1(TC))           AND DMPSX(XC,TC-1))            = (DMPSX(XC,TC)           / DMPSX(XC,TC-1)-1)*100;
 DTINSXY(XC,TC)$((NOT T1(TC))          AND DTINSX(XC,TC-1))           = (DTINSX(XC,TC)          / DTINSX(XC,TC-1)-1)*100;
 EGXY(XC,TC)$((NOT T1(TC))             AND EGX(XC,TC-1))              = (EGX(XC,TC)             / EGX(XC,TC-1)-1)*100;
 EHXY(H,XC,TC)$((NOT T1(TC))           AND EHX(H,XC,TC-1))            = (EHX(H,XC,TC)           / EHX(H,XC,TC-1)-1)*100;
 EXRXY(XC,TC)$((NOT T1(TC))            AND EXRX(XC,TC-1))             = (EXRX(XC,TC)            / EXRX(XC,TC-1)-1)*100;
 FSAVXY(XC,TC)$((NOT T1(TC))           AND FSAVX(XC,TC-1))            = (FSAVX(XC,TC)           / FSAVX(XC,TC-1)-1)*100;
 GADJXY(XC,TC)$((NOT T1(TC))           AND GADJX(XC,TC-1))            = (GADJX(XC,TC)           / GADJX(XC,TC-1)-1)*100;
 GOVSHRXY(XC,TC)$((NOT T1(TC))         AND GOVSHRX(XC,TC-1))          = (GOVSHRX(XC,TC)         / GOVSHRX(XC,TC-1)-1)*100;
 GSAVXY(XC,TC)$((NOT T1(TC))           AND GSAVX(XC,TC-1))            = (GSAVX(XC,TC)           / GSAVX(XC,TC-1)-1)*100;
 HPOPXY(H,XC,TC)$((NOT T1(TC))         AND HPOPX(H,XC,TC-1))          = (HPOPX(H,XC,TC)         / HPOPX(H,XC,TC-1)-1)*100;
 IADJXY(IT,XC,TC)$((NOT T1(TC))        AND IADJX(IT,XC,TC-1))         = (IADJX(IT,XC,TC)        / IADJX(IT,XC,TC-1)-1)*100;
 INVSHRXY(XC,TC)$((NOT T1(TC))         AND INVSHRX(XC,TC-1))          = (INVSHRX(XC,TC)         / INVSHRX(XC,TC-1)-1)*100;
* MPSXY(INS,XC,TC)$((NOT T1(TC))        AND MPSX(INS,XC,TC-1))         = (MPSX(INS,XC,TC)        / MPSX(INS,XC,TC-1)-1)*100;
 MPSADJXY(XC,TC)$((NOT T1(TC))         AND MPSADJX(XC,TC-1))          = (MPSADJX(XC,TC)         / MPSADJX(XC,TC-1)-1)*100;
 PAXY(A,XC,TC)$((NOT T1(TC))           AND PAX(A,XC,TC-1))            = (PAX(A,XC,TC)           / PAX(A,XC,TC-1)-1)*100;
 PARXY(A,RD,XC,TC)$((NOT T1(TC))       AND PARX(A,RD,XC,TC-1))        = (PARX(A,RD,XC,TC)       / PARX(A,RD,XC,TC-1)-1)*100;
 PDDXY(C,XC,TC)$((NOT T1(TC))          AND PDDX(C,XC,TC-1))           = (PDDX(C,XC,TC)          / PDDX(C,XC,TC-1)-1)*100;
 PDSXY(C,XC,TC)$((NOT T1(TC))          AND PDSX(C,XC,TC-1))           = (PDSX(C,XC,TC)          / PDSX(C,XC,TC-1)-1)*100;
 PEXY(C,RW,XC,TC)$((NOT T1(TC))        AND PEX(C,RW,XC,TC-1))         = (PEX(C,RW,XC,TC)        / PEX(C,RW,XC,TC-1)-1)*100;
 PINTAXY(A,RD,XC,TC)$((NOT T1(TC))     AND PINTAX(A,RD,XC,TC-1))      = (PINTAX(A,RD,XC,TC)     / PINTAX(A,RD,XC,TC-1)-1)*100;
 PMXY(C,RW,XC,TC)$((NOT T1(TC))        AND PMX(C,RW,XC,TC-1))         = (PMX(C,RW,XC,TC)        / PMX(C,RW,XC,TC-1)-1)*100;
 PQXY(C,XC,TC)$((NOT T1(TC))           AND PQX(C,XC,TC-1))            = (PQX(C,XC,TC)           / PQX(C,XC,TC-1)-1)*100;
 PVAXY(A,RD,XC,TC)$((NOT T1(TC))       AND PVAX(A,RD,XC,TC-1))        = (PVAX(A,RD,XC,TC)       / PVAX(A,RD,XC,TC-1)-1)*100;
 PWEXY(C,RW,XC,TC)$((NOT T1(TC))       AND PWEX(C,RW,XC,TC-1))        = (PWEX(C,RW,XC,TC)       / PWEX(C,RW,XC,TC-1)-1)*100;
 PWMXY(C,RW,XC,TC)$((NOT T1(TC))       AND PWMX(C,RW,XC,TC-1))        = (PWMX(C,RW,XC,TC)       / PWMX(C,RW,XC,TC-1)-1)*100;
 PXXY(C,XC,TC)$((NOT T1(TC))           AND PXX(C,XC,TC-1))            = (PXX(C,XC,TC)           / PXX(C,XC,TC-1)-1)*100;
 PXACXY(A,C,XC,TC)$((NOT T1(TC))       AND PXACX(A,C,XC,TC-1))        = (PXACX(A,C,XC,TC)       / PXACX(A,C,XC,TC-1)-1)*100;
 QAXY(A,XC,TC)$((NOT T1(TC))           AND QAX(A,XC,TC-1))            = (QAX(A,XC,TC)           / QAX(A,XC,TC-1)-1)*100;
 QARXY(A,RD,XC,TC)$((NOT T1(TC))       AND QARX(A,RD,XC,TC-1))        = (QARX(A,RD,XC,TC)       / QARX(A,RD,XC,TC-1)-1)*100;
 QDXY(C,XC,TC)$((NOT T1(TC))           AND QDX(C,XC,TC-1))            = (QDX(C,XC,TC)           / QDX(C,XC,TC-1)-1)*100;
 QEXY(C,RW,XC,TC)$((NOT T1(TC))        AND QEX(C,RW,XC,TC-1))         = (QEX(C,RW,XC,TC)        / QEX(C,RW,XC,TC-1)-1)*100;
 QFXY(F,A,RD,XC,TC)$((NOT T1(TC))      AND QFX(F,A,RD,XC,TC-1))       = (QFX(F,A,RD,XC,TC)      / QFX(F,A,RD,XC,TC-1)-1)*100;
 QFSXY(F,XC,TC)$((NOT T1(TC))          AND QFSX(F,XC,TC-1))           = (QFSX(F,XC,TC)          / QFSX(F,XC,TC-1)-1)*100;
 QGXY(C,XC,TC)$((NOT T1(TC))           AND QGX(C,XC,TC-1))            = (QGX(C,XC,TC)           / QGX(C,XC,TC-1)-1)*100;
 QHXY(C,H,XC,TC)$((NOT T1(TC))         AND QHX(C,H,XC,TC-1))          = (QHX(C,H,XC,TC)         / QHX(C,H,XC,TC-1)-1)*100;
 QHAXY(A,H,XC,TC)$((NOT T1(TC))        AND QHAX(A,H,XC,TC-1))         = (QHAX(A,H,XC,TC)        / QHAX(A,H,XC,TC-1)-1)*100;
 QINTXY(C,A,XC,TC)$((NOT T1(TC))       AND QINTX(C,A,XC,TC-1))        = (QINTX(C,A,XC,TC)       / QINTX(C,A,XC,TC-1)-1)*100;
 QINTAXY(A,RD,XC,TC)$((NOT T1(TC))     AND QINTAX(A,RD,XC,TC-1))      = (QINTAX(A,RD,XC,TC)     / QINTAX(A,RD,XC,TC-1)-1)*100;
 QINVXY(C,IT,XC,TC)$((NOT T1(TC))      AND QINVX(C,IT,XC,TC-1))       = (QINVX(C,IT,XC,TC)      / QINVX(C,IT,XC,TC-1)-1)*100;
 QMXY(C,RW,XC,TC)$((NOT T1(TC))        AND QMX(C,RW,XC,TC-1))         = (QMX(C,RW,XC,TC)        / QMX(C,RW,XC,TC-1)-1)*100;
 QQXY(C,XC,TC)$((NOT T1(TC))           AND QQX(C,XC,TC-1))            = (QQX(C,XC,TC)           / QQX(C,XC,TC-1)-1)*100;
 QTXY(C,XC,TC)$((NOT T1(TC))           AND QTX(C,XC,TC-1))            = (QTX(C,XC,TC)           / QTX(C,XC,TC-1)-1)*100;
 QVAXY(A,RD,XC,TC)$((NOT T1(TC))       AND QVAX(A,RD,XC,TC-1))        = (QVAX(A,RD,XC,TC)       / QVAX(A,RD,XC,TC-1)-1)*100;
 QXXY(C,XC,TC)$((NOT T1(TC))           AND QXX(C,XC,TC-1))            = (QXX(C,XC,TC)           / QXX(C,XC,TC-1)-1)*100;
 QXACXY(A,C,XC,TC)$((NOT T1(TC))       AND QXACX(A,C,XC,TC-1))        = (QXACX(A,C,XC,TC)       / QXACX(A,C,XC,TC-1)-1)*100;
 TABSXY(XC,TC)$((NOT T1(TC))           AND TABSX(XC,TC-1))            = (TABSX(XC,TC)           / TABSX(XC,TC-1)-1)*100;
 TINSXY(INS,XC,TC)$((NOT T1(TC))       AND TINSX(INS,XC,TC-1))        = (TINSX(INS,XC,TC)       / TINSX(INS,XC,TC-1)-1)*100;
 TINSADJXY(XC,TC)$((NOT T1(TC))        AND TINSADJX(XC,TC-1))         = (TINSADJX(XC,TC)        / TINSADJX(XC,TC-1)-1)*100;
 TAXY(A,RD,XC,TC)$((NOT T1(TC))        AND TAX(A,RD,XC,TC-1))         = (TAX(A,RD,XC,TC)        / TAX(A,RD,XC,TC-1)-1)*100;
 TMXY(C,RW,XC,TC)$((NOT T1(TC))        AND TMX(C,RW,XC,TC-1))         = (TMX(C,RW,XC,TC)        / TMX(C,RW,XC,TC-1)-1)*100;
 TQXY(C,XC,TC)$((NOT T1(TC))           AND TQX(C,XC,TC-1))            = (TQX(C,XC,TC)           / TQX(C,XC,TC-1)-1)*100;
 TRIIXY(INS,INSP,XC,TC)$((NOT T1(TC))  AND TRIIX(INS,INSP,XC,TC-1))   = (TRIIX(INS,INSP,XC,TC)  / TRIIX(INS,INSP,XC,TC-1)-1)*100;
 WFXY(F,XC,TC)$((NOT T1(TC))           AND WFX(F,XC,TC-1))            = (WFX(F,XC,TC)           / WFX(F,XC,TC-1)-1)*100;
 WFDISTXY(F,A,RD,XC,TC)$((NOT T1(TC))  AND WFDISTX(F,A,RD,XC,TC-1))   = (WFDISTX(F,A,RD,XC,TC)  / WFDISTX(F,A,RD,XC,TC-1)-1)*100;
 YFXY(F,XC,TC)$((NOT T1(TC))           AND YFX(F,XC,TC-1))            = (YFX(F,XC,TC)           / YFX(F,XC,TC-1)-1)*100;
 YGXY(XC,TC)$((NOT T1(TC))             AND YGX(XC,TC-1))              = (YGX(XC,TC)             / YGX(XC,TC-1)-1)*100;
 YIFXY(INS,F,XC,TC)$((NOT T1(TC))      AND YIFX(INS,F,XC,TC-1))       = (YIFX(INS,F,XC,TC)      / YIFX(INS,F,XC,TC-1)-1)*100;
 YIXY(INS,XC,TC)$((NOT T1(TC))         AND YIX(INS,XC,TC-1))          = (YIX(INS,XC,TC)         / YIX(INS,XC,TC-1)-1)*100;
 trnsfrxy(INS,ACNT,XC,TC)$((NOT T1(TC)) AND trnsfrx(INS,ACNT,XC,TC-1)) = (trnsfrx(INS,ACNT,XC,TC) / trnsfrx(INS,ACNT,XC,TC-1)-1)*100;

*Average annual compound growth rates -------------------------

 ALPHAVAXA(A,RD,XC)     $SUM(T1, ALPHAVAX(A,RD,XC,T1))   = ((SUM(TN, ALPHAVAX(A,RD,XC,TN))  / SUM(T1, ALPHAVAX(A,RD,XC,T1))  )**(1/TNUM)-1)*100;
 CPIXA(XC)              $SUM(T1, CPIX(XC,T1))            = ((SUM(TN, CPIX(XC,TN))           / SUM(T1, CPIX(XC,T1))           )**(1/TNUM)-1)*100;
 DPIXA(XC)              $SUM(T1, DPIX(XC,T1))            = ((SUM(TN, DPIX(XC,TN))           / SUM(T1, DPIX(XC,T1))           )**(1/TNUM)-1)*100;
 DMPSXA(XC)             $SUM(T1, DMPSX(XC,T1))           = ((SUM(TN, DMPSX(XC,TN))          / SUM(T1, DMPSX(XC,T1))          )**(1/TNUM)-1)*100;
 DTINSXA(XC)            $SUM(T1, DTINSX(XC,T1))          = ((SUM(TN, DTINSX(XC,TN))         / SUM(T1, DTINSX(XC,T1))         )**(1/TNUM)-1)*100;
 EGXA(XC)               $SUM(T1, EGX(XC,T1))             = ((SUM(TN, EGX(XC,TN))            / SUM(T1, EGX(XC,T1))            )**(1/TNUM)-1)*100;
 EHXA(H,XC)             $SUM(T1, EHX(H,XC,T1))           = ((SUM(TN, EHX(H,XC,TN))          / SUM(T1, EHX(H,XC,T1))          )**(1/TNUM)-1)*100;
 EXRXA(XC)              $SUM(T1, EXRX(XC,T1))            = ((SUM(TN, EXRX(XC,TN))           / SUM(T1, EXRX(XC,T1))           )**(1/TNUM)-1)*100;
 FSAVXA(XC)             $SUM(T1, FSAVX(XC,T1))           = ((SUM(TN, FSAVX(XC,TN))          / SUM(T1, FSAVX(XC,T1))          )**(1/TNUM)-1)*100;
 GADJXA(XC)             $SUM(T1, GADJX(XC,T1))           = ((SUM(TN, GADJX(XC,TN))          / SUM(T1, GADJX(XC,T1))          )**(1/TNUM)-1)*100;
 GOVSHRXA(XC)           $SUM(T1, GOVSHRX(XC,T1))         = ((SUM(TN, GOVSHRX(XC,TN))        / SUM(T1, GOVSHRX(XC,T1))        )**(1/TNUM)-1)*100;
*GSAVXA(XC)             $SUM(T1, GSAVX(XC,T1))           = ((SUM(TN, GSAVX(XC,TN))          / SUM(T1, GSAVX(XC,T1))          )**(1/TNUM)-1)*100;
 HPOPXA(H,XC)           $SUM(T1, HPOPX(H,XC,T1))         = ((SUM(TN, HPOPX(H,XC,TN))        / SUM(T1, HPOPX(H,XC,T1))        )**(1/TNUM)-1)*100;
 IADJXA(IT,XC)          $SUM(T1, IADJX(IT,XC,T1))        = ((SUM(TN, IADJX(IT,XC,TN))       / SUM(T1, IADJX(IT,XC,T1))       )**(1/TNUM)-1)*100;
 INVSHRXA(XC)           $SUM(T1, INVSHRX(XC,T1))         = ((SUM(TN, INVSHRX(XC,TN))        / SUM(T1, INVSHRX(XC,T1))        )**(1/TNUM)-1)*100;
* MPSXA(INS,XC)          $SUM(T1, MPSX(INS,XC,T1))        = ((SUM(TN, MPSX(INS,XC,TN))       / SUM(T1, MPSX(INS,XC,T1))       )**(1/TNUM)-1)*100;
*MPSADJXA(XC)           $SUM(T1, MPSADJX(XC,T1))         = ((SUM(TN, MPSADJX(XC,TN))        / SUM(T1, MPSADJX(XC,T1))        )**(1/TNUM)-1)*100;
 PAXA(A,XC)             $SUM(T1, PAX(A,XC,T1))           = ((SUM(TN, PAX(A,XC,TN))          / SUM(T1, PAX(A,XC,T1))          )**(1/TNUM)-1)*100;
 PARXA(A,RD,XC)         $SUM(T1, PARX(A,RD,XC,T1))       = ((SUM(TN, PARX(A,RD,XC,TN))      / SUM(T1, PARX(A,RD,XC,T1))      )**(1/TNUM)-1)*100;
 PDDXA(C,XC)            $SUM(T1, PDDX(C,XC,T1))          = ((SUM(TN, PDDX(C,XC,TN))         / SUM(T1, PDDX(C,XC,T1))         )**(1/TNUM)-1)*100;
 PDSXA(C,XC)            $SUM(T1, PDSX(C,XC,T1))          = ((SUM(TN, PDSX(C,XC,TN))         / SUM(T1, PDSX(C,XC,T1))         )**(1/TNUM)-1)*100;
 PEXA(C,RW,XC)          $SUM(T1, PEX(C,RW,XC,T1))        = ((SUM(TN, PEX(C,RW,XC,TN))       / SUM(T1, PEX(C,RW,XC,T1))       )**(1/TNUM)-1)*100;
 PINTAXA(A,RD,XC)       $SUM(T1, PINTAX(A,RD,XC,T1))     = ((SUM(TN, PINTAX(A,RD,XC,TN))    / SUM(T1, PINTAX(A,RD,XC,T1))    )**(1/TNUM)-1)*100;
 PMXA(C,RW,XC)          $SUM(T1, PMX(C,RW,XC,T1))        = ((SUM(TN, PMX(C,RW,XC,TN))       / SUM(T1, PMX(C,RW,XC,T1))       )**(1/TNUM)-1)*100;
 PQXA(C,XC)             $SUM(T1, PQX(C,XC,T1))           = ((SUM(TN, PQX(C,XC,TN))          / SUM(T1, PQX(C,XC,T1))          )**(1/TNUM)-1)*100;
 PVAXA(A,RD,XC)         $SUM(T1, PVAX(A,RD,XC,T1))       = ((SUM(TN, PVAX(A,RD,XC,TN))      / SUM(T1, PVAX(A,RD,XC,T1))      )**(1/TNUM)-1)*100;
 PWEXA(C,RW,XC)         $SUM(T1, PWEX(C,RW,XC,T1))       = ((SUM(TN, PWEX(C,RW,XC,TN))      / SUM(T1, PWEX(C,RW,XC,T1))      )**(1/TNUM)-1)*100;
 PWMXA(C,RW,XC)         $SUM(T1, PWMX(C,RW,XC,T1))       = ((SUM(TN, PWMX(C,RW,XC,TN))      / SUM(T1, PWMX(C,RW,XC,T1))      )**(1/TNUM)-1)*100;
 PXXA(C,XC)             $SUM(T1, PXX(C,XC,T1))           = ((SUM(TN, PXX(C,XC,TN))          / SUM(T1, PXX(C,XC,T1))          )**(1/TNUM)-1)*100;
 PXACXA(A,C,XC)         $SUM(T1, PXACX(A,C,XC,T1))       = ((SUM(TN, PXACX(A,C,XC,TN))      / SUM(T1, PXACX(A,C,XC,T1))      )**(1/TNUM)-1)*100;
 QAXA(A,XC)             $SUM(T1, QAX(A,XC,T1))           = ((SUM(TN, QAX(A,XC,TN))          / SUM(T1, QAX(A,XC,T1))          )**(1/TNUM)-1)*100;
 QARXA(A,RD,XC)         $SUM(T1, QARX(A,RD,XC,T1))       = ((SUM(TN, QARX(A,RD,XC,TN))      / SUM(T1, QARX(A,RD,XC,T1))      )**(1/TNUM)-1)*100;
 QDXA(C,XC)             $SUM(T1, QDX(C,XC,T1))           = ((SUM(TN, QDX(C,XC,TN))          / SUM(T1, QDX(C,XC,T1))          )**(1/TNUM)-1)*100;
 QEXA(C,RW,XC)          $SUM(T1, QEX(C,RW,XC,T1))        = ((SUM(TN, QEX(C,RW,XC,TN))       / SUM(T1, QEX(C,RW,XC,T1))       )**(1/TNUM)-1)*100;
 QFXA(F,A,RD,XC)        $SUM(T1, QFX(F,A,RD,XC,T1))      = ((SUM(TN, QFX(F,A,RD,XC,TN))     / SUM(T1, QFX(F,A,RD,XC,T1))     )**(1/TNUM)-1)*100;
 QFSXA(F,XC)            $SUM(T1, QFSX(F,XC,T1))          = ((SUM(TN, QFSX(F,XC,TN))         / SUM(T1, QFSX(F,XC,T1))         )**(1/TNUM)-1)*100;
 QGXA(C,XC)             $SUM(T1, QGX(C,XC,T1))           = ((SUM(TN, QGX(C,XC,TN))          / SUM(T1, QGX(C,XC,T1))          )**(1/TNUM)-1)*100;
 QHXA(C,H,XC)           $SUM(T1, QHX(C,H,XC,T1))         = ((SUM(TN, QHX(C,H,XC,TN))        / SUM(T1, QHX(C,H,XC,T1))        )**(1/TNUM)-1)*100;
 QHAXA(A,H,XC)          $SUM(T1, QHAX(A,H,XC,T1))        = ((SUM(TN, QHAX(A,H,XC,TN))       / SUM(T1, QHAX(A,H,XC,T1))       )**(1/TNUM)-1)*100;
 QINTXA(C,A,XC)         $SUM(T1, QINTX(C,A,XC,T1))       = ((SUM(TN, QINTX(C,A,XC,TN))      / SUM(T1, QINTX(C,A,XC,T1))      )**(1/TNUM)-1)*100;
 QINTAXA(A,RD,XC)       $SUM(T1, QINTAX(A,RD,XC,T1))     = ((SUM(TN, QINTAX(A,RD,XC,TN))    / SUM(T1, QINTAX(A,RD,XC,T1))    )**(1/TNUM)-1)*100;
 QINVXA(C,IT,XC)        $SUM(T1, QINVX(C,IT,XC,T1))      = ((SUM(TN, QINVX(C,IT,XC,TN))     / SUM(T1, QINVX(C,IT,XC,T1))     )**(1/TNUM)-1)*100;
 QMXA(C,RW,XC)          $SUM(T1, QMX(C,RW,XC,T1))        = ((SUM(TN, QMX(C,RW,XC,TN))       / SUM(T1, QMX(C,RW,XC,T1))       )**(1/TNUM)-1)*100;
 QQXA(C,XC)             $SUM(T1, QQX(C,XC,T1))           = ((SUM(TN, QQX(C,XC,TN))          / SUM(T1, QQX(C,XC,T1))          )**(1/TNUM)-1)*100;
 QTXA(C,XC)             $SUM(T1, QTX(C,XC,T1))           = ((SUM(TN, QTX(C,XC,TN))          / SUM(T1, QTX(C,XC,T1))          )**(1/TNUM)-1)*100;
 QVAXA(A,RD,XC)         $SUM(T1, QVAX(A,RD,XC,T1))       = ((SUM(TN, QVAX(A,RD,XC,TN))      / SUM(T1, QVAX(A,RD,XC,T1))      )**(1/TNUM)-1)*100;
 QXXA(C,XC)             $SUM(T1, QXX(C,XC,T1))           = ((SUM(TN, QXX(C,XC,TN))          / SUM(T1, QXX(C,XC,T1))          )**(1/TNUM)-1)*100;
 QXACXA(A,C,XC)         $SUM(T1, QXACX(A,C,XC,T1))       = ((SUM(TN, QXACX(A,C,XC,TN))      / SUM(T1, QXACX(A,C,XC,T1))      )**(1/TNUM)-1)*100;
 TABSXA(XC)             $SUM(T1, TABSX(XC,T1))           = ((SUM(TN, TABSX(XC,TN))          / SUM(T1, TABSX(XC,T1))          )**(1/TNUM)-1)*100;
 TINSXA(INS,XC)         $SUM(T1, TINSX(INS,XC,T1))       = ((SUM(TN, TINSX(INS,XC,TN))      / SUM(T1, TINSX(INS,XC,T1))      )**(1/TNUM)-1)*100;
 TINSADJXA(XC)          $SUM(T1, TINSADJX(XC,T1))        = ((SUM(TN, TINSADJX(XC,TN))       / SUM(T1, TINSADJX(XC,T1))       )**(1/TNUM)-1)*100;
 TAXA(A,RD,XC)          $SUM(T1, TAX(A,RD,XC,T1))        = ((SUM(TN, TAX(A,RD,XC,TN))       / SUM(T1, TAX(A,RD,XC,T1))       )**(1/TNUM)-1)*100;
 TMXA(C,RW,XC)          $SUM(T1, TMX(C,RW,XC,T1))        = ((SUM(TN, TMX(C,RW,XC,TN))       / SUM(T1, TMX(C,RW,XC,T1))       )**(1/TNUM)-1)*100;
 TQXA(C,XC)             $SUM(T1, TQX(C,XC,T1))           = ((SUM(TN, TQX(C,XC,TN))          / SUM(T1, TQX(C,XC,T1))          )**(1/TNUM)-1)*100;
 TRIIXA(INS,INSP,XC)    $SUM(T1, TRIIX(INS,INSP,XC,T1))  = ((SUM(TN, TRIIX(INS,INSP,XC,TN)) / SUM(T1, TRIIX(INS,INSP,XC,T1)) )**(1/TNUM)-1)*100;
 WFXA(F,XC)             $SUM(T1, WFX(F,XC,T1))           = ((SUM(TN, WFX(F,XC,TN))          / SUM(T1, WFX(F,XC,T1))          )**(1/TNUM)-1)*100;
 WFDISTXA(F,A,RD,XC)    $SUM(T1, WFDISTX(F,A,RD,XC,T1))  = ((SUM(TN, WFDISTX(F,A,RD,XC,TN)) / SUM(T1, WFDISTX(F,A,RD,XC,T1)) )**(1/TNUM)-1)*100;
 YFXA(F,XC)             $SUM(T1, YFX(F,XC,T1))           = ((SUM(TN, YFX(F,XC,TN))          / SUM(T1, YFX(F,XC,T1))          )**(1/TNUM)-1)*100;
 YGXA(XC)               $SUM(T1, YGX(XC,T1))             = ((SUM(TN, YGX(XC,TN))            / SUM(T1, YGX(XC,T1))            )**(1/TNUM)-1)*100;
 YIFXA(INS,F,XC)        $SUM(T1, YIFX(INS,F,XC,T1))      = ((SUM(TN, YIFX(INS,F,XC,TN))     / SUM(T1, YIFX(INS,F,XC,T1))     )**(1/TNUM)-1)*100;
 YIXA(INS,XC)           $SUM(T1, YIX(INS,XC,T1))         = ((SUM(TN, YIX(INS,XC,TN))        / SUM(T1, YIX(INS,XC,T1))        )**(1/TNUM)-1)*100;
 trnsfrxa(INS,ACNT,XC)  $SUM(T1, trnsfrx(INS,ACNT,XC,T1)) = ((SUM(TN, trnsfrx(INS,ACNT,XC,TN)) / SUM(T1, trnsfrx(INS,ACNT,XC,T1)))**(1/TNUM)-1)*100;


*Price indices ------------------------------------------------

 pdwt(C)  = PDD0(C)*QD0(C)/SUM(CP, PDD0(CP)*QD0(CP));
 pwewt(C,RW) = pwe0(C,RW)*QE0(C,RW)/SUM((CP,RWP), pwe0(CP,RWP)*QE0(CP,RWP));
 pwmwt(C,RW) = pwm0(C,RW)*QM0(C,RW)/SUM((CP,RWP), pwm0(CP,RWP)*QM0(CP,RWP));
 pwwt('EXP') = (SUM((CP,RW), pwe0(CP,RW)*QE0(CP,RW))) / (SUM((CP,RW), pwe0(CP,RW)*QE0(CP,RW)) + SUM((CP,RW), pwm0(CP,RW)*QM0(CP,RW)));
 pwwt('IMP') = (SUM((CP,RW), pwm0(CP,RW)*QM0(CP,RW))) / (SUM((CP,RW), pwe0(CP,RW)*QE0(CP,RW)) + SUM((CP,RW), pwm0(CP,RW)*QM0(CP,RW)));


*Macrotab -----------------------------------------------------

*Data from all periods
 MACROTABX('QINVTOT',XC,TC)       = SUM((C,IT), PQ0(C)*QINVX(C,IT,XC,TC));
 MACROTABX('QGTOT',XC,TC)         = SUM(C, PQ0(C)*QGX(C,XC,TC));
 MACROTABX('QHTOT',XC,TC)         = SUM((C,H), PQ0(C)*QHX(C,H,XC,TC));
 MACROTABX('QABSTOT',X,TC)        = MACROTABX('QINVTOT',X,TC) + MACROTABX('QGTOT',X,TC) + MACROTABX('QHTOT',X,TC);
 MACROTABX('QETOT',XC,TC)         = SUM((C,RW), PE0(C,RW)*QEX(C,RW,XC,TC));
 MACROTABX('QMTOT',XC,TC)         = SUM((C,RW), PM0(C,RW)*QMX(C,RW,XC,TC));
 MACROTABX('CPI',XC,TC)           = 100*CPIX(XC,TC);
 MACROTABX('NEXR',XC,TC)          = 100*EXRX(XC,TC);
 MACROTABX('PDIND',XC,TC)         = 100*SUM(C, pdwt(C)*PDDX(C,XC,TC));
 MACROTABX('PWEIND',XC,TC)        = 100*SUM((C,RW), pwex(C,RW,XC,TC)*pwewt(C,RW))/SUM((C,RW), pwe0(C,RW)*pwewt(C,RW));
 MACROTABX('PWMIND',XC,TC)        = 100*SUM((C,RW), pwmx(C,RW,XC,TC)*pwmwt(C,RW))/SUM((C,RW), pwm0(C,RW)*pwmwt(C,RW));
 MACROTABX('TOFT',XC,TC)          = 100*MACROTABX('PWEIND',XC,TC)/MACROTABX('PWMIND',XC,TC);
 MACROTABX('PWIND',XC,TC)         = pwwt('EXP')*MACROTABX('PWEIND',XC,TC) +  pwwt('IMP')*MACROTABX('PWMIND',XC,TC);
 MACROTABX('REXR',XC,TC)          = MACROTABX('NEXR',XC,TC)*MACROTABX('PWIND',XC,TC)/MACROTABX('PDIND',XC,TC);
 MACROTABX('INVGDP',XC,TC)        = 100*(SUM((C,IT), PQX(C,XC,TC)*QINVX(C,IT,XC,TC))+SUM(C, PQX(C,XC,TC)*qdst(C)))/GDPTAB1('NOMINAL','GDPMP',XC,TC);
 MACROTABX('PRVSAVGDP',XC,TC)     = 100*SUM(INSDNG, MPSX(INSDNG,XC,TC)*((1-TINSX(INSDNG,XC,TC))*YIX(INSDNG,XC,TC)))/GDPTAB1('NOMINAL','GDPMP',XC,TC);
 MACROTABX('FORSAVGDP',XC,TC)     = 100*EXRX(XC,TC)*FSAVX(XC,TC)/GDPTAB1('NOMINAL','GDPMP',XC,TC);
 MACROTABX('TRDDEFGDP',XC,TC)     = 100*SUM((C,RW), PMX(C,RW,XC,TC)*QMX(C,RW,XC,TC) - PEX(C,RW,XC,TC)*QEX(C,RW,XC,TC))/GDPTAB1('NOMINAL','GDPMP',XC,TC);
 MACROTABX('GOVSAVGDP',XC,TC)     = 100*GSAVX(XC,TC)/GDPTAB1('NOMINAL','GDPMP',XC,TC);
 MACROTABX('IMPTAXGDP',XC,TC)$GDPTAB1('NOMINAL','GDPMP',XC,TC) = 100*SUM((CM,RW), TMX(CM,RW,XC,TC)*PWMX(CM,RW,XC,TC)*QMX(CM,RW,XC,TC)*EXRX(XC,TC))/GDPTAB1('NOMINAL','GDPMP',XC,TC);
 MACROTABX('DIRTAXGDP',XC,TC)$GDPTAB1('NOMINAL','GDPMP',XC,TC) = 100*(SUM(INSDNG, TINSX(INSDNG,XC,TC)*YIX(INSDNG,XC,TC)) + SUM(F, tf(F)*YFX(F,XC,TC)))/GDPTAB1('NOMINAL','GDPMP',XC,TC);

 MACROTAB(SIND,XC)       = SUM(TN, MACROTABX(SIND,XC,TN));
 MACROTAB(SIND,'INIT')   = SUM(T1, MACROTABX(SIND,'BASE',T1));

 MACROTABXA(SINDP,XC)     = ((MACROTAB(SINDP,XC)/MACROTAB(SINDP,'INIT'))**(1/TNUM)-1)*100;
 MACROTABXA(SINDDEV,XC)   =  (MACROTAB(SINDDEV,XC) - MACROTAB(SINDDEV,'INIT'))/TNUM;

 MACROTABXY(SINDP,XC,TC)$MACROTABX(SINDP,XC,TC-1)    = (MACROTABX(SINDP,XC,TC)/MACROTABX(SINDP,XC,TC-1)-1)*100;
 MACROTABXY(SINDDEV,XC,TC)$MACROTABX(SINDDEV,XC,TC-1) = MACROTABX(SINDDEV,XC,TC) - MACROTABX(SINDDEV,XC,TC-1);

 MACROTAB(SINDGR,XC)     = ((MACROTAB(SINDGR,XC)/MACROTAB(SINDGR,'INIT'))**(1/TNUM)-1)*100;
 MACROTAB(SIND,XC)$(SINDP(SIND) AND NOT SINDGR(SIND)) = (MACROTAB(SIND,XC)/MACROTAB(SIND,'INIT')-1)*100;
 MACROTAB(SINDDEV,XC)   =  MACROTAB(SINDDEV,XC) - MACROTAB(SINDDEV,'INIT');

*Tables other than MACROTAB ------------------------------

 QHTAB(H,XC)                    = SUM((TN,C), PQ0(C)*QHX(C,H,XC,TN));
 QHTAB(H,'INIT')                = SUM(C, PQ0(C)*QH0(C,H));
 QHTAB('TOTAL',X)               = SUM((TN,C,H), PQ0(C)*QHX(C,H,X,TN));
 QHTAB(H,XC)$QHTAB(H,'INIT')    = ((QHTAB(H,XC)/QHTAB(H,'INIT'))**(1/TNUM)-1)*100;

 YFTAB(F,XC)                    = SUM((TN,A,RD), WFX(F,XC,TN)*WFDISTX(F,A,RD,XC,TN)*QFX(F,A,RD,XC,TN));
 YFTAB(F,'INIT')                = SUM((A,RD), WF0(F)*WFDIST0(F,A,RD)*QF0(F,A,RD));
 YFTAB('TOTAL',X)               = SUM(F, YFTAB(F,X));
 YFTAB(F,XC)$YFTAB(F,'INIT')    = ((YFTAB(F,XC)/YFTAB(F,'INIT'))**(1/TNUM)-1)*100;

 QATAB(A,XC)                    = SUM(TN, PA0(A)*QAX(A,XC,TN));
 QATAB(A,'INIT')                = PA0(A)*QA0(A);
 QATAB('TOTAL',X)               = SUM((A,TN), PA0(A)*QAX(A,X,TN));
 QATAB(A,XC)$QATAB(A,'INIT')    = ((QATAB(A,XC)/QATAB(A,'INIT'))**(1/TNUM)-1)*100;

 PATAB(A,XC)                    = SUM(TN, PAX(A,XC,TN));
 PATAB(A,'INIT')                = PA0(A);
 PATAB(A,XC)$PATAB(A,'INIT')    = ((PATAB(A,XC)/PATAB(A,'INIT'))**(1/TNUM)-1)*100;

*Checking model solutions for errors ---------------------

*If error in the negative price/quantity segment, one or more solution prices
*or quantities are negative.
 NEGPWARN(C,XC,TC)$(
  ((PDDX(C,XC,TC) LT 0) OR (PDSX(C,XC,TC) LT 0) OR
  (SUM(RW, PEX(C,RW,XC,TC)) LT 0) OR (SUM(RW, PMX(C,RW,XC,TC)) LT 0)  OR
  (PQX(C,XC,TC) LT 0)  OR (SUM(RW, PWEX(C,RW,XC,TC)) LT 0) OR
  (SUM(RW, PWMX(C,RW,XC,TC)) LT 0) OR (PXX(C,XC,TC) LT 0)  OR
  (SMIN(A, PXACX(A,C,XC,TC)) LT 0) )) = 1/0;

 NEGQWARN(C,XC,TC)$(
  ((QDX(C,XC,TC) LT 0) OR
  (SUM(RW, QMX(C,RW,XC,TC)) LT 0) OR (QQX(C,XC,TC) LT 0) OR
  (SUM(RW, QEX(C,RW,XC,TC)) LT 0) OR (QXX(C,XC,TC) LT 0) OR
  (SMIN(A, QXACX(A,C,XC,TC)) LT 0) )) = 1/0;

 NEGWFWARN(F,XC,TC)$(((WFX(F,XC,TC) LT 0) OR (SMIN((RD,A), WFDISTX(F,A,RD,XC,TC)) LT 0))) = 1/0;

 NEGQFWARN(F,XC,TC)$(((QFSX(F,XC,TC) LT 0) OR (SMIN((RD,A), QFX(F,A,RD,XC,TC)) LT 0))) = 1/0;

*If error here, check displays of GDPGAP to find it.
 GAPWARN(XC,TC)$((GDPGAP(XC,TC) GT 1E-4)) = 1/0;

*If error here, check displays of SAMBUDGAP for hints about the source
 WALRASWARN(XC,TC)$((ABS(WALRASX(XC,TC)) GT 1E-4)) = 1/0;

*If error here, check displays of SAMBUDGAP and GDPGAP to find it. Also check WALRASX.
*Conditional printing of error check
 DISPLAY$(SMAX((XC,TC), ABS(GDPGAP(XC,TC))) GT 1E-4)       GDPGAP ;

*Fatal error check here. Not really necessary to be fatal.
 GAPWARNING(XC,TC)  = ABS(GDPGAP(XC,TC))  ;
 DISPLAY$(SMAX((XC,TC), GAPWARNING(XC,TC)) GT 1E-4) GAPWARNING ;
 GAPWARNING(XC,TC)$((GAPWARNING(XC,TC) GT 1E-4)) = 1/0 ;

*Error checking on Walras variable and conditional printing
 DISPLAY$(SMAX((XC,TC), ABS(WALRASX(XC,TC))) GT 1E-4) WALRASX ;

*Including the gini coefficient*
*$include includes\gini.inc



