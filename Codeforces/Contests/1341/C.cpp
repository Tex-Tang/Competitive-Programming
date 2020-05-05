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
    int n;cin >> n;
    int a[n];
    vp d;
    for(int i = 0;i < n;i++){
      cin >> a[i];
    }
    d.push_back({a[0],a[0]});
    for(int i = 1;i < n;i++){
      if(a[i] == a[i - 1] + 1){
        d.back().second = a[i];
      }else{
        d.push_back({a[i],a[i]});
      }
    }
    bool flag = true;
    if(d.back().first != 1){
      cout << "No" << endl;
      continue;
    }
    for(int i = d.size() - 2;i >= 0;i--){
      if(d[i].first != d[i + 1].second + 1){
        flag = false;
      }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}