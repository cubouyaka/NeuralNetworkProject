#include <fstream>
#include <string.h>
#include <iostream>
#include "matrix.h"
#include <cstdlib>

//ask the user to choose a mode
Matrix * askMode(int *n, int *m);
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
//calcul the weight matrix
Matrix calculWeightMatrix(Matrix * vectors,int *n);
//show m vectors (nx1) 
void showMany(Matrix * vectors, int * n, int * m);
