#include<bits/stdc++.h>

using namespace std;

int main(){
  long long n,m;
  cin >> n >> m;
  for(int i = 0;i < m;i++){
    long long z;cin >> z;
    n -= z;
  }
  if(n < 0) cout << -1;
  else cout << n;
}