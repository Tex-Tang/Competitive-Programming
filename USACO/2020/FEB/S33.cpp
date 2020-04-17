#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define MAXN 2501
vector <int> graph[MAXN];
int c[MAXN];
bool visited[MAXN];
int root = 0;
int dfs(int u){
  visited[u] = true;
  if(graph[u].size() == 1 && visited[graph[u][0]]){
    return 12 - c[u];
  }
  int res = 0;
  for(int v : graph[u]){
    if(!visited[v]){
      res += dfs(v);
    }
  }
  if(root == u) return res;
  return 12 - ((c[u] + res + 1) % 12);
}

int main(){
  int N; cin >> N;
  for(int i = 1;i <= N;i++) cin >> c[i];
  for(int i = 0;i < N - 1;i++){
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int ans = 0;
  for(int i = 1;i <= N;i++){
    for(int j = 1;j <= N;j++) visited[j] = false;
    root = i;
    int res = dfs(i);
    cout << i << " " << res << endl;
    if((c[i] + res - 1) % 12 == 0 || (c[i] + res) % 12 == 0){ ans++; cout << i << endl; }
  }
  cout << ans;
}

/*
3
11 10 11
1 2
2 3
*/