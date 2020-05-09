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
    ll n;int k;cin >> n >> k;    

    // n odd k odd
    if(n & 1 && k & 1 && n >= k){
      cout << "YES" << endl;
      for(int i = 0;i < k - 1;i++) cout << 1 << " ";
      cout << n - (k - 1) << endl;
    }
    // n even k odd
    else if(!(n & 1) && k & 1 && n >= 2*k){
      cout << "YES" << endl;
      for(int i = 0;i < k - 1;i++) cout << 2 << " ";
      cout << n - 2*(k - 1) << endl;
    }
    // n even k even
    else if(!(n & 1) && !(k & 1) && n >= k){
      cout << "YES" << endl;
      for(int i = 0;i < k - 1;i++) cout << 1 << " ";
      cout << n - (k - 1) << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}