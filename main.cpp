#include "utils.h"

int main(){

  int * n = (int *)(malloc(sizeof(int*)));
  int * m = (int *)(malloc(sizeof(int*)));
  Matrix * vectors = askMode(n,m);

  recognition(vectors,n,m);
  //Matrix test(3,3);
  //test.show();
  /*
  Matrix w = calculWeightMatrix(vectors,n,m);
  std::cout << "\n--WEIGHT MATRIX--";
  w.show();

  /*
  Matrix a(2,3);
  Matrix b(3,2);
  a.setValue(0,0,2);
  a.setValue(0,2,5);
  a.setValue(1,2,26);
  a.setValue(0,1,2);
  a.setValue(1,1,2);
  a.setValue(1,0,2);
  b.setValue(1,0,-1);
  b.setValue(1,1,-2);
  b.setValue(0,1,-2);
  b.setValue(0,0,-1);
  b.setValue(2,0,32);
  b.setValue(2,1,41);

  a.show();
  b.show();

  Matrix mm = multiplication(a,b);
  mm.show();
*/

  return 0;
}
