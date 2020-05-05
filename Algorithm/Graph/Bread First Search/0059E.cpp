#include <bits/stdc++.h>

using namespace std;

struct T{
  int a, b, c;
};
bool operator < (T f, T s) {
  if (f.a != s.a) return f.a < s.a;
  if (f.b != s.b) return f.b < s.b;
  return f.c < s.c;
}
int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector <int> adj[n + 1];
  queue <pair<int,int>> q;
  set <T> triplets;
  int best[n + 1][n + 1];
  pair<int,int> parent[n + 1][n + 1];
  for(int i = 0;i < m;i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 0;i < k;i++){
    int a,b,c;
    cin >> a >> b >> c;
    triplets.insert({a ,b , c});
  }
  for(int i = 1;i <= n;i++)
    for(int j = 1;j <= n;j++)
      best[i][j] = -1;
  for(int i = 0;i < adj[1].size();i++){
    best[1][adj[1][i]] = 1;
    q.push(make_pair(1, adj[1][i]));
  }
  while(!q.empty()){
    int a = q.front().first;
    int b = q.front().second;
    q.pop();
    for(int i = 0;i < adj[b].size();i++){
      int c = adj[b][i];
      if(best[b][c] == -1 && triplets.find({a, b, c}) == triplets.end()){
          best[b][c] = best[a][b] + 1;
          q.push({b, c});
          parent[b][c] = {a, b};
      }
    }
  }
  bool flag = false;
  int sol_c = 1e9;
  int sol_u = 0;
  for(auto &it : adj[n]){
    if(best[it][n] != -1){
      flag = true;
      sol_c = min(sol_c, best[it][n]);
      if(sol_c == best[it][n]) sol_u = it;
    }
  }
  
  if(!flag){ cout << -1; return 0; }
  cout << sol_c << endl;
  vector <int> path;
  int a = sol_u;
  int b = n;
  path.push_back(b);
  path.push_back(a);
  while(a != 1){
    pair<int,int> p = parent[a][b];
    a = p.first;
    b = p.second;
    path.push_back(a);
  }
  reverse(path.begin(), path.end());
  for(auto &u : path){
    cout << u << " ";
  }
}