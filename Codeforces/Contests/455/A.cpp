#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<x<<endl;
#define v(T) vector<T>
#define vv(T) v(v(T))
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;


int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n;
  cin >> n;
  vl cnt(1e5 + 1, 0);
  vl dp(1e5 + 1, 0);
  for(int i = 0;i < n;i++){
    int z;cin >> z;
    cnt[z]++;
  }

  dp[1] = cnt[1];
  dp[2] = max(cnt[2]*2, dp[1]);
  for(int i = 3;i <= 1e5;i++){
    dp[i] = max(cnt[i]*i + dp[i - 2], dp[i - 1]);
  }
  cout << dp[1e5];
  
}