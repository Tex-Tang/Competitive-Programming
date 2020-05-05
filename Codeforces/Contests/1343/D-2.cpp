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
  for(int t = 0;t < T;t++){
    int n,k;cin >> n >> k;
    int a[n];
    vector<int> change(2*k + 2,0);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n/2;i++){
      int l = a[i], r = a[n - i - 1];
      int lowest = min(l,r) + 1;
      int highest = max(l,r) + k;
      change[l + r]--;
      change[l + r + 1]++;
      change[lowest]--;
      change[highest + 1]++;
    }
    int sum = 0, mincost = n;
    for(int i = 2;i <= 2*k;i++){
      sum += change[i];
      mincost = min(mincost, n + sum);
    }
    cout << mincost << endl;
  }
}