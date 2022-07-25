***This program calculates the gini coefficient***
***25 November 2010***

Sets
 hhd9(HP)           the richest 10% of households
                    /hhd-91, hhd-92, hhd-93, hhd-94, hhd-95/
 hh                 household by decile
                    /hhd-0, hhd-1, hhd-2, hhd-3, hhd-4, hhd-5, hhd-6,
                     hhd-7, hhd-8, hhd9/
 v                  parameters assigned via table
                    /rank/
;

Parameters
 income(hh,X,T)     Income of household deciles
 rank(hh)           Weight given to each household
 gini(X,T)          Gini Coefficient
 mean(X,T)          Average income of deciles
;

Table d(v,hh)

         hhd-0   hhd-1   hhd-2   hhd-3   hhd-4   hhd-5   hhd-6   hhd-7   hhd-8  hhd9
  rank    10       9       8       7       6       5       4      3        2     1
;

 income('hhd-0',XC,TC)=YIX('hhd-0',XC,TC);
 income('hhd-1',XC,TC)=YIX('hhd-1',XC,TC);
 income('hhd-2',XC,TC)=YIX('hhd-2',XC,TC);
 income('hhd-3',XC,TC)=YIX('hhd-3',XC,TC);
 income('hhd-4',XC,TC)=YIX('hhd-4',XC,TC);
 income('hhd-5',XC,TC)=YIX('hhd-5',XC,TC);
 income('hhd-6',XC,TC)=YIX('hhd-6',XC,TC);
 income('hhd-7',XC,TC)=YIX('hhd-7',XC,TC);
 income('hhd-8',XC,TC)=YIX('hhd-8',XC,TC);
 income('hhd9',XC,TC)=YIX('hhd-91',XC,TC)+YIX('hhd-92',XC,TC)
                      +YIX('hhd-93',XC,TC)+YIX('hhd-94',XC,TC)
                      +YIX('hhd-95',XC,TC);

 rank(hh)=d('rank',hh);
 mean(XC,TC)=sum(hh,income(hh,XC,TC))/10;
 gini(XC,TC)=((10+1)/(10-1))-((2/(10*(10-1)*mean(XC,TC)))*(sum(hh,(rank(hh)*income(hh,XC,TC)))));

Display rank, income, mean, gini;

