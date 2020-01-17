#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  if(n == 0){
    cout << "O-|-OOOO";
    return 0;
  }
  int d = log10(n) + 1;
  for(int i = 0;i < d;i++){
    int z = (n / (int)pow(10, i)) % 10;
    if(z >= 5){
      z-=5;
      cout << "-O|";
      for(int j = 0;j < z;j++) cout << "O";
      cout << "-";
      for(int j = z;j < 4;j++) cout << "O";
    }else{
      cout << "O-|";
      for(int j = 0;j < z;j++) cout << "O";
      cout << "-";
      for(int j = z;j < 4;j++) cout << "O";
    }
    cout << endl;
  }
}