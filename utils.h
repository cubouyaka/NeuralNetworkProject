#include <fstream>
#include <string.h>
#include <iostream>
#include "matrix.h"
#include <cstdlib>


////// ASK/LOAD FUNCTIONS ///////

//ask the user to choose a mode
Matrix* askMode(int *n, int *m);
//when the user choose manual mode
Matrix * askManual(int *n, int *m);
//when the user choose to use a file
Matrix *  askFile(int *n, int *m);
//ask the user for value to fill the matrix
int askValue(int i, int j);
//load the file (file mode only)
Matrix * loadFile(char * name, int *n, int *m);
//check if the input file exist or not
bool exist(char * name);

////// CALCULS FUNCTIONS ////////

//calcul the weight matrix
Matrix calculWeightMatrix(Matrix * vectors,int *n,int *m);
//calcul (1/N)*[sum of x(s,i)*x(s,j) for s=1 to s=m]
double hebbRule(Matrix * vectors, int i, int j,int *n, int * m);
//Recognition calcul to find stability or double-cycle
void recognition(Matrix * vectors,int *n, int *m);

////// OTHERS FUNCTIONS /////////

//show m vectors (nx1)
void showMany(Matrix * vectors, int * n, int * m);
