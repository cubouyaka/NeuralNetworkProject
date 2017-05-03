#include "utils.h"

int main()
{
  
  //// READ THE FILE AND CONSTRUCT VECTORS ////
  int * n = (int *)(malloc(sizeof(int*)));
  int * m = (int *)(malloc(sizeof(int*)));
  Matrix * vectors = askMode(n,m);
  showMany(vectors,n,m);
  Matrix w = calculWeightMatrix(vectors,n,m);
  w.show();

  /*

  Matrix test1(3,3);
  test1.setValue(0,0,1);
  test1.setValue(0,1,1);
  test1.setValue(1,1,1);
  test1.setValue(1,0,1);
  test1.setValue(2,1,1);
  test1.setValue(2,2,1);
  test1.setValue(1,2,1);
  test1.setValue(2,0,1);
  test1.setValue(0,2,1);

  Matrix test(3,3);
  test.setValue(0,0,1);
  test.setValue(0,1,1);
  test.setValue(1,1,1);
  test.setValue(1,0,1);
  test.setValue(2,1,1);
  test.setValue(2,2,1);
  test.setValue(1,2,1);
  test.setValue(2,0,1);
  test.setValue(0,2,1);

  Matrix test2(3,3);
  test2.setValue(0,0,1);
  test2.setValue(0,1,1);
  test2.setValue(1,1,1);
  test2.setValue(1,0,1);
  test2.setValue(2,1,1);
  test2.setValue(2,2,1);
  test2.setValue(1,2,1);
  test2.setValue(2,0,1);
  test2.setValue(0,2,1);

  test.show();
  test1.show();
  test2.show();
  */
  return 0;
}
