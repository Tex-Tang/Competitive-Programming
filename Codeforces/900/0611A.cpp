#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  string s;cin >> s;
  cin >> s;
  if(s == "week"){
    if(n == 5 || n == 6){
      cout << 53;
    }else{
      cout << 52;
    }
  }else{
    if(n < 30) cout << 12;
    if(n == 30) cout << 11;
    if(n == 31) cout << 7;
  }
}