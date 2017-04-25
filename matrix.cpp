#include "matrix.h"
#include <iostream>
#include <string.h>
using namespace std;

Matrix::Matrix(int _n, int _m){
  n = _n;
  m = _m;
  matrix = new int*[n];
  for(int i = 0; i < n; ++i)
    matrix[i] = new int[m];
}

Matrix::~Matrix()
{
  for (int i = 0; i < n; i++)
    delete[] matrix[i];
  delete[] matrix;
}

void Matrix::setValue(int i, int j, int value){
  matrix[i][j] = value;
}

void Matrix::show(){
  cout << "-------------------" <<endl;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j)
      cout << matrix[i][j] <<" ";
    cout << endl;
  }
  cout << "-------------------" <<endl;
}
