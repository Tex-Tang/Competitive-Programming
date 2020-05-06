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
  int T;cin >> T;
  for(int t = 0;t < T;t++){
    int n,m;
    cin >> n >> m;
    if(n == 1 || m == 1) cout << "YES" << endl;
    else if(n == 2 && m == 2){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}