#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;cin >> n;
  for(int i = 4;i < n;i++){
    int d = n -i;
    bool s = false;
    for(int j = 2;j < i;j++){
      if(i % j == 0){ s = true; break; }
    }
    bool t = false;
    for(int j = 2;j < d;j++){
      if(d % j == 0){ t = true; break; }
    }
    if(s && t){
      cout << i << " " << d;
      return 0;
    }
  }
}