PARAMETER
*Variables to be captured
 CPIX(X,T)                     consumer price index (PQ-based)
 DEBTX(X,T)                    accumulated foreign debt
 DPIX(X,T)                     index for domestic producer prices (PDS-based)
 DMPSX(X,T)                    change in marginal propensity to save for selected inst
 DTINSX(X,T)                   change in domestic institution tax share
 EGX(X,T)                      total current government expenditure
 EHX(H,X,T)                    household consumption expenditure
 EXRX(X,T)                     exchange rate
 FBORX(X,T)                    annual foreign borrowing
 FSAVX(X,T)                    foreign savings
 GADJX(X,T)                    government demand scaling factor
 GOVSHRX(X,T)                  govt consumption share of absorption
 GSAVX(X,T)                    government savings
 HPOPX(H,X,T)                  household populations
 IADJX(IT,X,T)                 investment scaling factor (for fixed capital formation)
 INVSHRX(X,T)                  investment share of absorption
 MPSX(INS,X,T)                 marginal propensity to save for dom non-gov inst ins
 MPSADJX(X,T)                  savings rate scaling factor
 PAX(A,X,T)                    output price of activity a
 PARX(A,RD,X,T)                output price of activity a
 PDDX(C,X,T)                   demand price for com'y c produced & sold domestically
 PDSX(C,X,T)                   supply price for com'y c produced & sold domestically
 PEX(C,RW,X,T)                 price of exports
 PINTAX(A,RD,X,T)              price of intermediate aggregate
 PMX(C,RW,X,T)                 price of imports
 PQX(C,X,T)                    price of composite good c
 PVAX(A,RD,X,T)                value added price
 PWEX(C,RW,X,T)                world price of exports
 PWMX(C,RW,X,T)                world price of imports
 PXX(C,X,T)                    average output price
 PXACX(A,C,X,T)                price of commodity c from activity a
 QAX(A,X,T)                    level of domestic activity
 QARX(A,RD,X,T)                level of domestic activity
 QDX(C,X,T)                    qnty of domestic sales
 QEX(C,RW,X,T)                 qnty of exports
 QFX(F,A,RD,X,T)               qnty demanded of factor f from activity a
 QFSX(F,X,T)                   qnty of factor supply
 QGX(C,X,T)                    qnty of government consumption
 QHX(C,H,X,T)                  qnty consumed of market commodity c by household h
 QHAX(A,H,X,T)                 qnty consumed of home commodity c fr act a by hhd h
 QINTX(C,A,X,T)                qnty of intermediate demand for c from activity a
 QINTAX(A,RD,X,T)              qnty of aggregate intermediate input
 QINVX(C,IT,X,T)               qnty of fixed investment demand
 QMX(C,RW,X,T)                 qnty of imports
 QQX(C,X,T)                    qnty of composite goods supply
 QTX(C,X,T)                    qnty of trade and transport demand for commodity c
 QVAX(A,RD,X,T)                qnty of aggregate value added
 QXX(C,X,T)                    qnty of aggregate marketed commodity output
 QXACX(A,C,X,T)                qnty of ouput of commodity c from activity a
 TABSX(X,T)                    total absorption
 TINSX(INS,X,T)                rate of direct tax on domestic institutions ins
 TINSADJX(X,T)                 direct tax scaling factor
 TAX(A,RD,X,T)                 activity tax rate
 TAADJX(X,T)                   activity tax scaling factor
 TAPSX(X,T)                    point change in activity tax rate
 TMX(C,RW,X,T)                 import tariff rate
 TQADJX(X,T)                   sales tax scaling factor
 TQX(C,X,T)                    indirect sales tax rate
 TQPSX(X,T)                    point change in sales tax rate
 TRIIX(INS,INSP,X,T)           transfers to dom. inst. insdng from insdngp
 WALRASX(X,T)                  savings-investment imbalance (should be zero)
 WFX(F,X,T)                    economy-wide wage (rent) for factor f
 WFDISTX(F,A,RD,X,T)           factor wage distortion variable
 YFX(F,X,T)                    factor income
 YGX(X,T)                      total current government income
 YIFX(INS,F,X,T)               income of institution ins from factor f
 YIX(INS,X,T)                  income of (domestic non-governmental) institution ins
 WALRASX(X,T)                  walras law value
*Parameters to be captured
 alphavax(A,RD,X,T)
 fprdx(F,A,RD,X,T)
 trnsfrx(INS,AC,X,T)
 BETAMX(C,H,X,T)               household marketed consumption shares
*Parameters to be saved
 QFS00(F)                      base year factor supply numbers (used for upward-sloping labor supply curves)

 tco2dx(X,T)
 tco2ex(X,T)
 tco2mx(X,T)
 rtco2ex(X,T)
 co2cx(C,X,T)
 co2ex(C,RW,X,T)
 co2mx(C,RW,X,T)

*FH
 yieldx(A,X,T)
 intax(A,RD,X,T)
 ivax(A,RD,X,T)
 ifax(F,A,RD,X,T)
 icax(C,A,RD,X,T)
 GDPMPX(X,T)
* TVAX(A,RD,X,T)
* TVAADJX(X,T)
* TVAPSX(X,T)
 PQIX(C,A,RD,X,T)
 PQHX(C,H,X,T)
 BETAMX(C,H,X,T)
 YG_DTAXX(X,T)               direct current government income
 YG_ITAXX(X,T)               indirect current government income
 YG_NTAXX(X,T)               other current government income - should be 0
;

 QFS00(F) = QFS0(F);





