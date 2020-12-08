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
  ll n,l;
  cin >> n >> l;
  ll a[n];
  for(int i = 0;i < n;i++) cin >> a[i];
  sort(a, a + n);
  double ans = max(a[0], l - a[n - 1]);
  for(int i = 1;i < n;i++){
    ans = max(ans, double(abs(a[i] - a[i - 1])) / 2);
  }
  cout << fixed << showpoint << setprecision(9);
  cout << ans;
}