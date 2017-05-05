#include "utils.h"
using namespace std;


////// ASK/LOAD FUNCTIONS ///////

Matrix * askMode(int *n, int *m){
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
    return askManual(n,m);
  else
    return askFile(n,m);
}


Matrix * askManual(int *n, int *m){

  cout << "How many vectors ? ";
  cin >> (*m);
  cout << "Of how many rows ? ";
  cin >> (*n);
  cout << endl;	

  Matrix * vectors = (Matrix *) malloc((*m) * sizeof(Matrix));
 
  int correct = 0;
  std::string answer;
  double tmp;

  while(!correct){
    for(int i = 0; i < (*m); i++){
      new (&(vectors[i])) Matrix((*n),1);
      cout << "Vector n-" << i+1 << ": (enter values one by one)"<<endl;
      for(int j = 0; j < (*n); j++){
	cin >> tmp;
	vectors[i].setValue(j,0,tmp);
      }
    }
    cout <<endl<< "Is it correct ? (y/n)"<<endl<<endl;
    showMany(vectors,n,m);
    cin >> answer;
    if(!answer.compare("yes") || !answer.compare("y"))
      correct = true;
  }
  
  Matrix weight = calculWeightMatrix(vectors,n,m);
  
  return vectors;
}

Matrix *  askFile(int *n, int *m){
  char file[100];
  //while the input file is not correct, we ask the user to choose one
  do {
    cout << "Choose a correct input file in the current folder : " << endl;
    cin >> file;
  }while(!exist(file));
  return loadFile(file,n,m);
}

int askValue(int i, int j){
  double value;
  cout << i <<","<<j<<" : ";
  cin >> value;
  return value;
}

Matrix * loadFile(char * name, int *n, int *m){
  ifstream  file;
  file.open(name, ios::in);

  file >> (*m); //set the number of vectors
  file >> (*n); //set the number of rows

  Matrix * vectors = (Matrix *) malloc((*m) * sizeof(Matrix));

  for(int i = 0; i < (*m); i++){
    new (&(vectors[i])) Matrix((*n),1);
    for(int j = 0; j < (*n); j++)
      file >> vectors[i].matrix[j][0];
  }

  file.close();
  showMany(vectors,n,m);

  return vectors;
}

bool exist(char * name){
  ifstream file(name);
  if(file.good()){
    file.close();
    return true;
  }else{
    cout << "\""<< name << "\"" << " doesn't exist, retry !" << endl;
    return false;
  }
}

////// CALCULS FUNCTIONS ////////

Matrix calculWeightMatrix(Matrix * vectors,int * n,int * m){
  Matrix w((*n),(*n)); //creating the weight matrix
  for(int i = 0; i < *n; i++)
    for(int j = 0; j < *n; j++)
      w.setValue(i,j,hebbRule(vectors,i,j,n,m));
  return w;
}

double hebbRule(Matrix * vectors, int i, int j, int *n, int * m){
  double result = 0;
  if(i == j)
    return result;
  for(int s = 0; s < *m; s++)
    result += vectors[s].matrix[i][0] * vectors[s].matrix[j][0];
  return result/(*n);
}

void recognition(Matrix * vectors,int *n, int *m){ 

  Matrix weight = calculWeightMatrix(vectors,n,m);
  cout << "\n--WEIGHT MATRIX--";
  weight.show();
  
  Matrix * u = (Matrix *) malloc((*m) * sizeof(Matrix));
  Matrix * v = (Matrix *) malloc((*m) * sizeof(Matrix));

  for(int i = 0; i < (*m); i++){
    new (&(u[i])) Matrix((*n),1);
    new (&(v[i])) Matrix((*n),1);
    u[i] = weight * vectors[i];
    v[i] = u[i].g();
  }

  cout << "\n--VECTORS U--\n\n";
  showMany(u,n,m);
  cout << "\n--VECTORS V--\n\n";
  showMany(v,n,m);

  int stable = 1;
  int double_c = 1; //if there is a double cycle
  for(int j = 0; j < *m; j++)
    if(!(v[j] == vectors[j]))
      stable = 0;
  
  if(stable)
    cout << "STABLE !!\n";
  else{
    Matrix * w = (Matrix *) malloc((*m) * sizeof(Matrix));
    for(int k = 0; k < (*m); k++){
      new (&(w[k])) Matrix((*n),1);
      w[k] = weight * u[k];
    }
    for(int l = 0; l < *m; l++)
      if(!(w[l] == u[l]))
	double_c = 0;

    if(double_c)
      cout << "Double cycle !\n";
  }

}

////// OTHERS FUNCTIONS /////////

void showMany(Matrix * vectors, int * n, int * m){
  int s = 12;
  cout << setfill(' ');  //fill with spaces
  for(int i = 0; i < (*m); i++)
    cout << "Vector n-" << i<< setw(s);
  cout << endl << setfill('-') << setw(s*(*m)) << "-" << endl;
  cout << setfill(' ');  //fill with spaces
  for(int j = 0; j < (*n); j++){
    for(int k = 0; k < (*m); k++){
      cout <<setw(s-5)<<vectors[k].matrix[j][0];
      cout<<setw(s-5) <<" ";
    }
    cout << endl;
  }
}
