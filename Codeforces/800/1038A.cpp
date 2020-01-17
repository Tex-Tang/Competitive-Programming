#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  int k;cin >> k;
  string s; cin >> s;
  int count[26];
  for(int i = 0;i < 26;i++) count[i] = 0;
  for(int i = 0;i < n;i++){
    count[s[i] - 'A']++;
  }
  int nmax = 10e5 + 1;
  for(int i = 0;i < k;i++){
    nmax = min(nmax, count[i]);
  }
  if(nmax == 0) cout << nmax;
  else cout << nmax*k;
}