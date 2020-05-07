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
    string str;
    cin >> str;
    int n = str.length();
    set<P> visited;
    int x = 0,y = 0,ans = 0;
    for(int i = 0;i < n;i++){
      int a = x, b = y;
      if(str[i] == 'N') y++;
      if(str[i] == 'S') y--;
      if(str[i] == 'W') x--;
      if(str[i] == 'E') x++;
      
      if(visited.find({x + a,y + b}) != visited.end()) ans++;
      else ans += 5;
      visited.insert({x + a,y + b});
    }
    cout << ans << endl;;
  }
}