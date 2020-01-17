#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  long long nmin = 10e9 + 1, nmax = 0;
  for(int i = 0;i < n;i++){
    long long z;cin >> z;
    nmax = max(nmax,z);
    nmin = min(nmin,z);
  }
  cout << nmax - nmin - n + 1;
}