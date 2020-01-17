#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;cin >> t;
  for(int i = 0;i < t;i++){
    int n,k;cin >> n >> k;
    string s = "";
    while(s.length() < n){
      for(int i = 0;i < k && s.length() < n;i++){
        s += char(int('a' + i));
      }
    }
    cout << s << endl;
  }
}