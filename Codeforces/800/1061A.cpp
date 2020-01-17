#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, s;
  cin >> n >> s;
  int ans = int(s / n) + (s % n == 0 ? 0 : 1);
  cout << ans;
}