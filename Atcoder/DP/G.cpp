#include <bits/stdc++.h>
 
using namespace std;
 
vector <vector <int> > graph;
vector <int> dp;
 
int dfs(int u){
  if(dp[u] != -1) return dp[u];
  int maxv = 0;
  for(int v: graph[u]){
    maxv = max(maxv, dfs(v));
  }
  dp[u] = 1 + maxv;
  return dp[u];
}
 
int main(){
  int n,m;
  cin >> n >> m;
  dp.assign(n + 1, -1);
  graph.assign(n + 1, vector<int>());
  for(int i = 0;i < m;i++){
    int u,v;cin >> u >> v;
    graph[u].push_back(v);
  }
  int maxv = 0;
  for(int i = 1;i <= n;i++){
    maxv = max(maxv, dfs(i));
  }
  cout << maxv - 1;
}