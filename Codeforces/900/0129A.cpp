#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;cin >> n;
  int odd = 0,even = 0;
  for(int i = 0;i < n;i++){
    int z;cin >> z;
    if(z % 2 == 0) even++;
    else odd++;
  }
  if(odd % 2 == 0){
    cout << even;
  }else{
    cout << odd;
  }
}