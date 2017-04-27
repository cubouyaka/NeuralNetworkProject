#include <fstream>
#include <string.h>
#include <iostream>
#include "matrix.h"
#include <cstdlib>
using namespace std;

Matrix calculWeightMatrix(Matrix * vectors,int n);

//check if the input file exist or not
bool exist(char * name)
{
  ifstream file(name);
  if(file.good()){
    file.close();
    return true;
  }else{
    cout << "\""<< name << "\"" << " doesn't exist, retry !" << endl;
    return false;
  }
}

Matrix * loadFile(char * name){
  int n,m;
  ifstream  file;
  file.open(name, ios::in);
  
  file >> n; //set the number of rows
  file >> m; //set the number of vectors

  Matrix * vectors = new Matrix[m];

  for(int i = 0; i < m; i++){
    vectors[i] = Matrix(n,1);
    for(int j = 0; j < n; j++)
      file >> vectors[i].matrix[j][0];
  }

  file.close();
  
  return vectors;
}

Matrix * askManual(){

  int n,m;
  cout << "How many vectors ? ";
  cin >> m;
  cout << "Of how many rows ? ";
  cin >> n;
  cout << endl;	

  Matrix * vectors = (Matrix *) malloc(m * sizeof(Matrix));
 
  int correct = 0;
  std::string answer;
  int tmp;

  for(int i = 0; i < m; i++){
    while(!correct){
      new (&(vectors[i])) Matrix(n,1);
      cout << "Vector n-" << i+1 << ": (enter values one by one)"<<endl;
      for(int j = 0; j < n; j++){
	cin >> tmp;
	vectors[i].setValue(j,0,tmp);
      }
      cout << "Vector n-" << i+1 << ", is it correct ? (y/n)" << endl;
      vectors[i].show();
      cin >> answer;
      if(!answer.compare("yes") || !answer.compare("y"))
	correct = true;
    }
    correct = false;
  }
  
  Matrix weight = calculWeightMatrix(vectors,n);
  
  return vectors;
}

Matrix *  askFile(){
  char file[100];
  //while the input file is not correct, we ask the user to choose one
  do {
    cout << "Choose a correct input file in the current folder : " << endl;
    cin >> file;
  }while(!exist(file));
  return loadFile(file);
}

/*
int askValue(int i, int j){
  int value;
  cout << i <<","<<j<<" : ";
  cin >> value;
  return value;
}
*/

Matrix * askMode(){
  int b = 0;
  char mode;
  do {
    cout << "Select a mode : Manual (m) or File (f) " << endl;
    cin >> mode;
    if((mode == 'f') || (mode == 'm'))
      b = 1;
    else
      cout << "Wrong mode, try again !"<<endl;
  }while(!b);
  if(mode == 'm')
    return askManual();
  else //if(mode == 'f')
    return askFile();
}

Matrix calculWeightMatrix(Matrix * vectors,int n){
  Matrix w(n,n); //creating the weight matrix
  /*
    TODO CALCULS
   */
  return w;
}

int main()
{
  //// READ THE FILE AND CONSTRUCT VECTORS ////
  Matrix * vectors = askMode();
  return 0;
}
