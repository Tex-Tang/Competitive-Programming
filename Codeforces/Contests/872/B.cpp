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

v(vl) st;
int lg;
long long query(int l, int r){
  long long minx = 10e9 + 1;
  for(int j = lg;j >= 0;j--){
    if((1 << j) <= r - l + 1){
      minx = min(minx, st[l][j]);
      l = l + (1 << j);
    }
  }
  return minx;
}


int main(){
  //ios_base::sync_with_stdio(0);
	//cin.tie(0);
  int n,k;
  cin >> n >> k;
  lg = int(log2(n));
  st.resize(n);
  long long maxx = -10e9 - 1;
  long long minx = 10e9 + 1;
  for(int i = 0;i < n;i++){
    st[i].resize(lg + 1);
    cin >> st[i][0];
    maxx = max(maxx,st[i][0]);
    minx = min(minx,st[i][0]);
  }
  
  if(k >= 3){
    cout << maxx << endl;
    return 0;
  }else if(k == 1){
    cout << minx << endl;
    return 0;
  }
  for (int j = 1; j <= lg; j++)
    for (int i = 0; i + (1 << j) <= n; i++)
      st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
  int l = 0,r = 1;
  long long maxxx = -10e9 - 1;
  while(r < n){
    maxxx = max(maxxx,max(query(0,l), query(r,n - 1)));
    l++;
    r++;
  }
  cout << maxxx;
  
}