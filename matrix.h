#include <iomanip>
#include <stdlib.h>
class Matrix {

 public:

  double ** matrix;
  int n; //number of rows
  int m; //number of columns
 
  ///////// CONSTRUCTORS /////////
  Matrix() {} //default constructor
  Matrix(int n, int m); //Creates a matrix nxm

  ///////// DESTRUCTOR ///////////
  ~Matrix();

  ///////// OPERATORS ////////////
  bool operator==(Matrix const& a);
  void operator=(Matrix const& a);
  Matrix operator*(Matrix const& a); //Matrix multiplication
  Matrix operator+(Matrix const& a); //Matrix addition

  ///////// METHODS //////////////
  void setValue(int i, int j, double value); //set the value X_i,j = value
  void show(); // print the matrix
  Matrix g(); //Recognition function g
};
