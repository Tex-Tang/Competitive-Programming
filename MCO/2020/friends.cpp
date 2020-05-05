#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector < vector<ll> > graph;
vector < ll > a;
vector < pair<ll,ll> > dp;

void dfs(int u, int pu){  
  for(int v: graph[u]){
    if(v == pu) continue;
    dfs(v,u);
    dp[u].first += max(dp[v].second,dp[v].first);
  }
  
  for(int v: graph[u]){
    if(v == pu) continue;
    if(u == 1){
      
    }
    dp[u].second = max(
      dp[u].second, 
      a[v] * a[u] + dp[u].first - max(dp[v].second,dp[v].first) + dp[v].first
    );
  }
}

int main(){
  int n;cin >> n;
  graph.resize(n);
  a.resize(n);
  dp.assign(n, {0,0});
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }
    
  for(int i = 0;i < n - 1;i++){
    int u,v;cin >> u >> v;
    graph[u - 1].push_back(v - 1);
    graph[v - 1].push_back(u - 1);
  }
  dfs(0,0);
  cout << max(dp[0].first,dp[0].second);
}