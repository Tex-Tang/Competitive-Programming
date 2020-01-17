#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int l,r;cin >> l >> r;
  for(int i = l;i <= r;i++){
    string s = std::to_string(i);
    bool exist[10];
    bool sc = true;
    for(int j = 0;j < 10;j++) exist[j] = false;
    for(int j = 0;j < s.length();j++){
      if(exist[s[j] - '0']){
        sc = false;
        break;
      }else{
        exist[s[j] - '0'] = true;
      }
    }
    if(sc){
      cout << s;
      return 0;
    }
  }
  cout << -1;
}