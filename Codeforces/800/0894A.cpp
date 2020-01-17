#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;cin >> s;
  string c = "QAQ";
  int count[s.length() + 1][4] = {{ 0 }};
  for(int i = 0;i <= 4;i++) count[0][i] = 0;
  for(int i = 0;i <= s.length();i++) count[i][0] = 1;
  for(int i = 1;i <= s.length();i++){
    for(int j = 1;j <= 4;j++){
      if(s[i - 1] == c[j - 1]){
        count[i][j] = count[i - 1][j - 1] + count[i - 1][j];
      }else{
        count[i][j] = count[i - 1][j];
      }
    }
  }

  cout << count[s.length()][3];
}