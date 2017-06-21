#IFNDEF _MKLKERNEL_H
#DEFINE _MKLKERNEL_H

struct mkl_option {
  char* algo;
  int stopvariation;
  int stopKKT;
  int stopdualitygap;

  double seuildiffsigma;
  double seuildiffconstraint;
  double seuildualitygap;

  double goldensearch_deltmax;
  double numericalpercision;
  double lambdareg;

  char* firstbasevariable;
  int nbitermax;
  int seuil;
  int seuilitermax;

  int miniter;
  int verbosesvm;
  int efficientkernel;
}

#ENDIF
