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
    long long a[n];
    for(int i = 0 ;i < n;i++) cin >> a[i];
    int to_l = (n - 1) / 2, to_r = to_l + 1;
    sort(a, a + n);
    while(to_r < n){
      cout << a[to_l] << " " << a[to_r] << " ";
      to_l--,to_r++;
    }
    if(n % 2 == 1) cout << a[0];
    cout << endl;
  }
}