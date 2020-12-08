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
  ll a[n];
  ll pre[n + 1];
  pre[0] = 0;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    if(i > 0) pre[i] = pre[i - 1] + a[i];
    else pre[i] = a[i];
  }

  int l = 0, r = n - 1;
  while(r > l){
    int sum_l = pre[l];
    int sum_r = pre[r] - pre[r - 1];
  }

}