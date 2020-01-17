#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  string s;cin >> s;
  string ans = "";
  int maxx = 0;
  char e;
  for(int i = 0;i < s.length();i++){
    int x = 0;
    char c = s[i];
    for(int j = s.length() - 1;j >= 0;j--){
      if(s[j] == s[i]) x++;
    }
    if(c > e){
      maxx = x;
      e = c;
    }
  }
  for(int i = 0;i < maxx;i++) cout << e;
}