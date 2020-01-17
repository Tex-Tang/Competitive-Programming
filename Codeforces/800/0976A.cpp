#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  string s;cin >> s;
  if(n == 1){
    if(s == "0") cout << 0;
    else cout << 1;
    return 0;
  }
  int oneN = 0;
  for(int i = 0;i < n;i++){
    if(s[i] == '1'){ oneN++; }
  }
  cout << 1;
  for(int i = 0;i < n - oneN;i++){
    cout << 0;
  }
}