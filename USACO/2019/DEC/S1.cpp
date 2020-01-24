#include <bits/stdc++.h>
#include <fstream>

using namespace std;
 
int main(){
  ifstream fin("moobuzz.in");
  ofstream fout("moobuzz.out");
  long long n;
  fin >> n;
  int j = n / 8 - 1;
  if(n % 8 == 0){
    fout << n / 8 * 15 - 1;
  }else{
    long long i = n / 8,j = 0;
    int p = 8 * i;
    for(i = i * 15;i < (n / 8 + 1)*15;i++){
      if(i % 3 != 0 && i % 5 != 0 && i % 15 != 0){
        j++;
        if(p + j == n){
          fout << i;
          return 0;
        }
      }
    }
  }
  
}