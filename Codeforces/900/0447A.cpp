#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int p,n;
  cin >> p >> n;
  bool exist[p];
  for(int i = 0;i < p;i++) exist[i] = false;
  for(int i = 0;i < n;i++){
    int z;cin >> z;
    if(exist[z % p]){
      cout << i + 1;
      return 0;
    }else{
      exist[z % p] = true;
    }
  }
  cout << -1;
}