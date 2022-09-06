*--------------------------------------------------------------
*SETUP AND CALL TIMES MODEL IN GAMS -------------------------------------
*--------------------------------------------------------------

  PUT  ShowRunNumber;
  RUNTIMES2.pc = 2;
  RUNTIMES2.nd = 5;
  RUNTIMES2.ap = 0;

  put "echo ", RUN.TL;

  PUTCLOSE "";

* Write executable for running eMOD with specified path and run-name
  PUT  RUNTIMES2;
  RUNTIMES2.pc = 2;
  RUNTIMES2.nd = 5;
  RUNTIMES2.ap = 0;

* will remove below when imported into ANSWER

  loop(MRUNCASE(RUN,eMODCASES), put ".\GHATIM\%TIMESfolder%\RUNTIMES.CMD ", "%workingfolder%":38,eMODCASES.TL:20,"%TIMESfolder%");

  PUTCLOSE "";

* Run TIMES model
 execute ".\GHATIM\%TIMESfolder%\ShowRunNumber.CMD"
 execute ".\GHATIM\%TIMESfolder%\RUNTIMES2.CMD"
 execute "echo --- Return to CGE model"

