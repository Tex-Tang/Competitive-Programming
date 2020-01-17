#include <bits/stdc++.h>

using namespace std;

int main(){
  bool s[1001];
  int n;cin >> n;
  for(int i = 0;i < 1001;i++) s[i] = false;
  for(int i = 0;i < n;i++){
    int z;cin >> z;
    s[z] = true;
  }
  for(int i = 1;i < 1000;i++){
    if(s[i - 1] && s[i] && s[i + 1]){
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}