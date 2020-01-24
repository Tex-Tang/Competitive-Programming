#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
  ifstream fin("shuffle.in");
  ofstream fout("shuffle.out");
  int n;
  fin >> n;
  int ind[n];
  for(int i = 0;i < n;i++){ 
    int z;
    fin >> z;
    ind[z - 1] = i;
  }
  string str[n];
  for(int i = 0;i < n;i++){
    fin >> str[i];
  }
  string strn[n];
  for(int i = 0;i < n;i++){ 
    strn[ind[ind[ind[i]]]] = str[i];
  }
  for(int i = 0;i < n;i++){ 
    fout << strn[i] << endl;;
  }
  
}