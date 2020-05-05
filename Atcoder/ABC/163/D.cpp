#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int main(){
  ll n,k;
  cin >> n >> k;
  ll ans = 0;
  for(ll i = k;i <= n + 1;i++){
    ll L = i * ( i - 1 ) / 2;
    ll R = (n * (n + 1) - ( n - i ) * ( n - i + 1)) / 2;
    ans = (ans % MOD + (R - L + 1) % MOD) % MOD;
  }
  cout << ans;
}