* this module is run at the end to compile energy sector emissions

*REPORT(PRC,COM,TC,RUN,Emiss)$EmisFactorCor(Com,Emiss,TC,RUN) = REPORT(PRC,COM,TC,RUN,'FlowIn')*EmisFactorCor(Com,Emiss,TC,RUN);
*REPORT(PRC,COM,TC,RUN,Emiss)$(Not EmisFactorCor(Com,Emiss,TC,RUN)) = REPORT(PRC,COM,TC,RUN,'FlowIn')*EmisFactor(Com,Emiss);

REPORT(PRC,COM,TC,RUN,Emiss) = REPORT(PRC,COM,TC,RUN,'FlowIn')*EmisFactor(Com,Emiss);

