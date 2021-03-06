#include "matrix.h"
#include <iostream>
#include <string.h>
using namespace std;

Matrix::Matrix(int _n, int _m){
  n = _n;
  m = _m;
  matrix = new double*[n];
  for(int i = 0; i < n; ++i){
    matrix[i] = new double[m];
    for(int j = 0; j < m; j++)
      this->setValue(i,j,0);
  }
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
      cout << setw(10) <<setprecision(4) << matrix[i][j];
    cout << endl;
  }
  cout << setfill('-') << setw(10*m) << "-" << endl;
}

bool Matrix::operator==(Matrix const& a){
  if((this->n != a.n) || (this->m != a.m))
    return false; 
  for(int i = 0; i < a.n; ++i)
    for(int j = 0; j < a.m; ++j)
      if(a.matrix[i][j] != this->matrix[i][j])
	return false;
  return true;
}

void Matrix::operator=(Matrix const& a){
  this->n = a.n;
  this->m = a.m;
  for(int i = 0; i < a.n; ++i)
    for(int j = 0; j < a.m; ++j)
      this->matrix[i][j] = a.matrix[i][j];
}

Matrix Matrix::operator*(Matrix const& a){
  if((this->m != a.n)){
    cout<<"ERROR (Matrix Multiplication): you try to multiply two matrices of different sizes\n";
    exit (EXIT_FAILURE);
  }
  Matrix result(this->n,a.m);
  for(int i = 0; i < this->n; ++i)
    for(int j = 0; j < a.m; ++j)
       for(int k = 0; k < a.n; ++k)
	result.matrix[i][j] += this->matrix[i][k] * a.matrix[k][j];
  return result;
}

Matrix Matrix::operator+(Matrix const& a){
  if((this->n != a.n) || (this->m != a.m)){
    cout<<"ERROR (Matrix Addition): you try to add two matrices of different sizes\n";
    exit (EXIT_FAILURE);
  }
  Matrix result(this->n,a.m);
  for(int i = 0; i < this->n; ++i)
    for(int j = 0; j < a.m; ++j)
	result.matrix[i][j] = this->matrix[i][j] + a.matrix[i][j];
  return result;
}

Matrix Matrix::g(){
  Matrix result(n,m);
  for(int i = 0; i < this->n; i++)
    for(int j = 0; j < this->m; j++)
      if(this->matrix[i][j] >= 0)
	result.matrix[i][j] = 1;
      else
	result.matrix[i][j] = -1;
  return result;
}
