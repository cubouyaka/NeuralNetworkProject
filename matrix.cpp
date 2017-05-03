#include "matrix.h"
#include <iostream>
#include <string.h>
using namespace std;

Matrix::Matrix(int _n, int _m){
  n = _n;
  m = _m;
  matrix = new double*[n];
  for(int i = 0; i < n; ++i)
    matrix[i] = new double[m];
}

Matrix::~Matrix()
{
  for (int i = 0; i < n; i++)
    delete[] matrix[i];
  delete[] matrix;
}

void Matrix::setValue(int i, int j, double value){
  matrix[i][j] = value;
}

void Matrix::show(){
  cout << endl << setfill('-') << setw(10*m) << "-" << endl;
  cout << setfill(' ');
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j)
      cout << setw(10) <<setprecision(3) << matrix[i][j];
    cout << endl;
  }
  cout << setfill('-') << setw(10*m) << "-" << endl;
}
