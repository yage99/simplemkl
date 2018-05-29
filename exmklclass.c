#include <stdio.h>
#include "mklkernel.h"
#include "csv.h"

int main(int argc, char** argv) {
  int nbiter = 1;
  double ratio = 0.5;
  char* data = "ionosphere";
  int C = 100;
  int verbose = 1;

  struct mkl_option options;

  options.algo="svmclass"; // Choice of algorithm in mklsvm can be either
                         // 'svmclass' or 'svmreg'
  //------------------------------------------------------
  // choosing the stopping criterion
  //------------------------------------------------------
  options.stopvariation=0; // use variation of weights for stopping criterion 
  options.stopKKT=0;       // set to 1 if you use KKTcondition for stopping criterion    
  options.stopdualitygap=1; // set to 1 for using duality gap for stopping criterion

  //------------------------------------------------------
  // choosing the stopping criterion value
  //------------------------------------------------------
  options.seuildiffsigma=1e-2;        // stopping criterion for weight variation 
  options.seuildiffconstraint=0.1;    // stopping criterion for KKT
  options.seuildualitygap=0.01;       // stopping criterion for duality gap

  //------------------------------------------------------
  // Setting some numerical parameters 
  //------------------------------------------------------
  options.goldensearch_deltmax=1e-1; // initial precision of golden section search
  options.numericalprecision=1e-8;   // numerical precision weights below this value
  // are set to zero 
  options.lambdareg = 1e-8;          // ridge added to kernel matrix 

  //------------------------------------------------------
  // some algorithms paramaters
  //------------------------------------------------------
  options.firstbasevariable="first"; // tie breaking method for choosing the base 
  // variable in the reduced gradient method 
  options.nbitermax=500;             // maximal number of iteration  
  options.seuil=0;                   // forcing to zero weights lower than this 
  options.seuilitermax=10;           // value, for iterations lower than this one 

  options.miniter=0;                 // minimal number of iterations 
  options.verbosesvm=0;              // verbosity of inner svm algorithm 
  options.efficientkernel=1;         // use efficient storage of kernels 

  char** kernelt = {"gaussian", "gaussian", "poly", "poly"};
  int** kerneloptionvect = {{0.5, 1, 2, 5, 6, 10, 12, 15, 17, 20}, {0.5, 1, 2, 5, 6, 10, 12, 15, 17, 20}, {1, 2, 3}, {1, 2, 3}};
  char** variablevec = {"all", "single", "all", "single"};

  int* classcode = {1, -1};

  int nbdata = 0;
  int dim = 0;
  double** x = loadCSV("ionosphere_x.txt", &nbdata, &dim);
  int* y = loadClassCSV("ionosphere_y.txt");

  int nbtrain = nbdata * ratio;

  for(int i = 0; i < nbiter; i++) {
    SplitedData* splitedData = createDataAppTest(x, y, nbtrain, classcode);
  }
}

void createDataAppTest(float** x, int** y, int nbtrain, int* classcode) {
  
}
