*r=simulation gdx=report fw=1 s=rep
SET
 AR                      all activity reporting accounts
 ARA(AR)                 aggregate activity reporting accounts
 CR                      all commodity reporting accounts
 CRA(CR)                 aggregate commodity reporting accounts
 FR                      all factor reporting accounts
 FRA(FR)                 aggregate factor reporting accounts
 HR                      all household reporting accounts
 HRA(HR)                 aggregate household reporting accounts
;

ALIAS (AR,ARP), (ARA,ARAP), (FR,FRP), (FRA,FRAP), (HR,HRP), (HRA,HRAP);

$include includes\3tables.inc

PARAMETER
*Mappings
 ACTAGG(A,RD,AR)         model activities to reporting activities
 COMAGG(C,CR)            model activities to reporting activities
 FACAGG(F,FR)            model factors to reporting factors
 HHDAGG(H,HR)            model households to reporting households
*Activities based tables
 GDPX(AR,X,T)            Real GDP at factor cost
 GDPXA(AR,X)             average annual growth in real GDP at factor cost
 GDPXY(AR,X,T)           year-on-year growth in real GDP at factor cost
 GDPXS(AR,X,T)           shares of real GDP at factor cost
*GDP at market prices
 GDPDX(IGDP,X,T)         Real GDP at market prices
 GDPDXA(IGDP,X)          average annual growth in real GDP at market prices
 GDPDXY(IGDP,X,T)        year-on-year growth in real GDP at market prices
 GDPDXS(IGDP,X,T)        shares of real GDP at market prices
*Factors based tables
 FACX(FR,X,T)            factor supplies
 FACXA(FR,X)             average annual growth in factor supplies
 FACXY(FR,X,T)           year-on-year growth in factor supplies
 FACRX(FR,X,T)           factor returns
 FACRXA(FR,X)            average annual growth in factor returns
 FACRXY(FR,X,T)          year-on-year growth in factor returns
*Households based tables
 POPX(HR,X,T)            household population
 POPXA(HR,X)             average annual household population growth
 POPXY(HR,X,T)           year-on-year household population growth
 HHDCX(HR,X,T)           household real consumption
 HHDCXA(HR,X)            average annual growth in household real consumption
 HHDCXY(HR,X,T)          year-on-year growth in household real consumption
 HHDPCX(HR,X,T)          household real per capita consumption
 HHDPCXA(HR,X)           average annual growth in per capita household real consumption
 HHDPCXY(HR,X,T)         year-on-year growth in per capita household real consumption
 HHDBC(CR,HR)            base year household consumption patterns
 HHDBY(HR,*)             base year household income patterns
*Foreign trade tables
 TREX(CR,X,T)            real export values
 TRMX(CR,X,T)            real import values
 NETX(CR,X,T)            net real trade values (+ is exported)
 TREXA(CR,X)             average annual growth in real export values
 TRMXA(CR,X)             average annual growth in real import values
 TREXY(CR,X,T)           year-on-year growth in real export values
 TRMXY(CR,X,T)           year-on-year growth in real import values
*Structural base tables (with aggregates)
 STRUCBASE2(AR,STRCOL)   economic structure in the base
 STRUCBASE3(CR,STRCOL)   economic structure in the base
;

$call "gdxxrw i=%reportdata% o=reportdata index=index!a6 checkdate"
$gdxin reportdata.gdx

$load   AR CR FR HR
$loaddc ARA CRA FRA HRA ACTAGG COMAGG FACAGG HHDAGG

