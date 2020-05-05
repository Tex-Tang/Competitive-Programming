#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, k, d;
  cin >> n >> k >> d;
  vector <pair<int,int>> adj[n + 1];
  bool visited_v[n + 1];
  bool visited_p[n + 1];
  int p[k];
  queue<int> q;
  for(int i = 0;i <= n;i++){
    visited_v[i] = false;
    visited_p[i] = false;
  }
  for(int i = 0;i < k;i++){
    cin >> p[i];
    q.push(p[i]);
    visited_v[p[i]] = true;
  }
  
  for(int i = 1;i < n;i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
  int ans = n - 1;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    visited_v[u] = true;
    for(int i = 0;i < adj[u].size();i++){
      int v = adj[u][i].first;
      int ind = adj[u][i].second;
      //cout << u << " " << v << endl;
      if(!visited_v[v]){
        visited_p[ind] = true;
        q.push(v);
        visited_v[v] = true;
      }
    }
  }
  vector <int> res;
  for(int i = 1;i < n;i++) if(!visited_p[i]) res.push_back(i);
  cout << res.size() << endl;
  for(auto &it : res){
    cout << it << " ";
  }
  
}