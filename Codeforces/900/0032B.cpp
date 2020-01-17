#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  string s;cin >> s;
  for(int i = 0;i < s.length();i++){
    if(i != s.length() - 1 && s[i] == '-' && s[i + 1] == '-'){
      cout << 2;
      i++;
    }else if(i != s.length() - 1 && s[i] == '-' && s[i + 1] == '.'){
      cout << 1;
      i++;
    }else if(s[i] == '.'){
      cout << 0;
    }
  }
}