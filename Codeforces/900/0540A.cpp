#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
  int n,ans = 0;cin >> n;
  string a,b;
  cin >> a;
  cin >> b;
  for(int i = 0;i < n;i++){
    int x = a[i] - '0', y = b[i] - '0';
    ans += min(abs(x-y), min(x,y) + 9 - max(x,y) + 1);
  }
  cout << ans;
}