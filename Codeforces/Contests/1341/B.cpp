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
  int T;cin >> T;
  for(int o = 0;o < T;o++){
    int n,k;
    cin >> n >> k;
    long long a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    bool dp[n];
    int sum = 0;
    dp[0] = 0;
    for(int i = 1;i < k;i++){
      dp[i] = a[i] > a[i + 1] && a[i] > a[i - 1];
      sum += dp[i];
    }
    int max_peak = sum - dp[k - 1];
    int max_l = 0;
    for(int l = k;l < n;l++){
      dp[l] = a[l] > a[l + 1] && a[l] > a[l - 1];
      if(l == n - 1) dp[l] = 0;
      sum += dp[l] - dp[l - k];
      int z = sum - dp[l - k + 1] - dp[l];
      if(z > max_peak) max_peak = z, max_l = l - k + 1;
    }
    cout << max_peak + 1 << " " << max_l + 1 << endl;
  }
}