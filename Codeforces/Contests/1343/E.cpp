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

vvi graph;

vi bfs(int u, int n){
  vi result(n + 1,-1);
  queue<int> q;
  q.push(u);
  result[u] = 0;
  while(!q.empty()){
    int f = q.front();
    q.pop();
    for(int v: graph[f]){
      if(result[v] == -1){
        result[v] = result[f] + 1;
        q.push(v);
      }
    }
  }
  return result;
}

int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  int T;cin >> T;
  for(int t = 0;t < T;t++){
    int n,m,a,b,c;
    cin >> n >> m >> a >> b >> c;
    long long p[m],pref[m + 1];
    for(int i = 0;i < m;i++) cin >> p[i];
    sort(p, p + m);
    pref[0] = 0;
    for(int i = 1;i <= m;i++) pref[i] = pref[i - 1] + p[i - 1];
    graph.assign(n + 1, vi());
    for(int i = 0;i < m;i++){
      int u,v;cin >> u >> v;
      graph[u].pb(v);
      graph[v].pb(u);
    }

    vi da = bfs(a,n);
    vi db = bfs(b,n);
    vi dc = bfs(c,n);
    long long minx = (long long)10e18;
    for(int i = 1;i <= n;i++){
      if(da[i] + db[i] + dc[i] > m) continue;
      minx = min(minx, pref[db[i]] + pref[da[i] + db[i] + dc[i]]);
    }
    cout << minx << endl;
  }
}