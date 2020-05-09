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
    int n0,n1,n2;
    cin >> n0 >> n1 >> n2;

    if(n1 == 0){
      if(n0 != 0){
        cout << string(n0 + 1, '0') << endl;
      }else{
        cout << string(n2 + 1, '1') << endl;
      }
      continue;
    }
    string str;
    for(int i = 0;i < n1 + 1;i++){
      if(i & 1) str += '0';
      else str += '1'; 
    }
    str.insert(1, string(n0, '0'));
    str.insert(0, string(n2, '1'));

    cout << str << endl;
  }
}