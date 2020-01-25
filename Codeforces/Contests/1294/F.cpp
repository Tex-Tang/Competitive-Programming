#include <bits/stdc++.h>

using namespace std;

vector<int> graph[200005];
int from_arr[200005];
pair<int,int> dfs(int v, int from, int dist){
  from_arr[v] = from;
  pair<int,int> res = make_pair(dist, v);
  for(int i = 0;i < graph[v].size();i++){
    if(graph[v][i] != from){
      res = max(res, dfs(graph[v][i], v, dist + 1));
    }
  }
  return res;
}

int main(){
  int n;
  cin >> n;
  
  for(int i = 0;i < n - 1;i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  pair <int,int> ds = dfs(1, -1, 0);
  pair <int,int> out = dfs(ds.second, -1, 0);
  vector <int> diamater;
  int v = out.second;
  while(v != ds.second){
    diamater.push_back(v);
    v = from_arr[v];
  }
  diamater.push_back(ds.second);
  if(diamater.size() == n){
    cout << n - 1 << endl << diamater[0] << " " << diamater[1] << " " << diamater.back();
  }else{
    queue<int> q;
    vector<int> dist(n + 1, -1);
    for(int i = 0;i < diamater.size();i++){
      dist[diamater[i]] = 0;
      q.push(diamater[i]);
    }
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(int i = 0;i < graph[v].size();i++){
        int to = graph[v][i];
        if(dist[to] == -1){
          dist[to] = dist[v] + 1;
          q.push(to);
        }
      }
    }
    pair <int,int> far = make_pair(dist[1], 1);
    for(int i = 2;i <= n;i++){
      far = max(far, make_pair(dist[i], i));
    }
    cout << diamater.size() - 1 + far.first << endl;
    cout << diamater[0] << " " << far.second << " " << diamater.back() << endl;
  }


}