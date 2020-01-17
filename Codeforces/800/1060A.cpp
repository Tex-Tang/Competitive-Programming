#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  string s;
  cin >> s;
  int z = 0;
  for(int i = 0;i < n;i++){
    if(s[i] == '8') z++;
  }
  cout << min(z, n / 11);
}