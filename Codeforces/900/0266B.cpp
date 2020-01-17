#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n,t;
  cin >> n >> t;
  string s;cin >> s;
  for(int i = 0;i < t;i++){
    int j = 0;
    while(j + 1 < n){
      if(s[j + 1] == 'G' && s[j] == 'B'){
        s[j] = 'G';
        s[j + 1] = 'B';
        j++;
      }
      j++;
    }
  }
  cout << s;
}