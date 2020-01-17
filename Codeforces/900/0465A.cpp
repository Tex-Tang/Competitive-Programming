#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;cin >> n;
  string s;cin >> s;
  if(s[0] == '1'){
    int j = 0;
    for(;j < n;j++){
      if(s[j] == '0') break;
    }
    if(j == n){ cout << j; }
    else{ cout << j + 1; }
  }else{
    cout << 1;
  }
}