#include <bits/stdc++.h>
#include <string>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool c[26];
  for(int i = 0;i < 26;i++) c[i] = false;
  for(int i = 0;i < n;i++){
      char z= tolower(s[i]);
      c[z - 'a'] = true;
  }
  for(int i = 0;i < 26;i++){
    
    if(c[i] == false){
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}