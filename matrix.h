#include <iomanip>
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

  ///////// METHODS //////////////
  void setValue(int i, int j, double value); //set the value X_i,j = value
  void show(); // print the matrix
};
