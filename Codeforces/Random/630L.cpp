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

// a^b
ll binpow(ll a,ll b){
  if(b == 0) return 1;
  ll res = binpow(a, b / 2);
  if(b % 2) return res * res * a;
  return res * res;
}

int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n;
  cin >> n;
  ll ans = 0;
  for(int i = 1;i <= n - 1;i++){
    ll res = 4, t = n - 2;
    if(i + n <= 2 * n - 2) res *= 3, t-= 1;
    if(i - 1 > 0) res *= 3, t -= 1;
    ans += res*binpow(4,t);
  }
  cout << ans;
}