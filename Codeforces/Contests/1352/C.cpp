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
    ll n,k;
    cin >> n >> k;
    // 3 1 * 3 + 1
    // 4 1 * 3 + 2
    // 5 2 * 3 + 1
    // 6 2 * 3 + 2
    // 7 3 * 3 + 1
    ll d = n*ll(k / (n - 1));
    if(k % (n - 1) == 0){ d -= 1; }
    else{ d += k % (n - 1);}
    cout << d << endl;
  }
}