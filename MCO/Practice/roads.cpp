#include <bits/stdc++.h>

using namespace std;

struct edge
{
  int u;
  int v;
  long long weight;
  bool operator<(edge const &other){
    return weight < other.weight;
  }
};
long long N, M, K;
vector<edge> red_edges;
vector<edge> special_edges;
vector<edge> blue_edges;
vector<int> visited;
vector<int> largest;
vector<int> parent;
vector<int> ranks;
vector<vector< pair<int,long long>>> result;

void dfs2(int u){
   for(pair<int,int> p: result[u]){
     int v = p.first, w = p.second;
     if(largest[v] == -1){
        largest[v] = max(largest[u],w);
        dfs2(v);
     }
   }
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (ranks[a] < ranks[b])
      swap(a, b);
    parent[b] = a;
    if (ranks[a] == ranks[b])
      ranks[a]++;
  }
}

int main(){
  cin >> N >> M >> K;
  int tree[N + 1];
  ranks.resize(N + 1);
  parent.resize(N + 1);
  largest.resize(N + 1);
  result.resize(N + 1);
  for(int v = 1;v <= N;v++){
    parent[v] = v;
    ranks[v] = 0;
    largest[v] = -1;
  }
  
  for(int i = 1;i <= M;i++){
    int u,v;
    long long w;
    cin >> u >> v >> w;
    if(u <= K && v <= K){
      red_edges.push_back(edge{u,v,w});
    }else if(u > K && v > K){
      blue_edges.push_back(edge{u,v,w});
    }else{
      special_edges.push_back(edge{u,v,w});
    }
  }

  sort(red_edges.begin(),red_edges.end());
  sort(special_edges.begin(),special_edges.end());
  sort(blue_edges.begin(),blue_edges.end());
  long long total_cost = 0;
  for(edge e: red_edges){
    if(find_set(e.u) != find_set(e.v)){
      total_cost += e.weight;
      result[e.u].push_back(make_pair(e.v,e.weight));
      result[e.v].push_back(make_pair(e.u,e.weight));
      union_sets(e.u, e.v);
    }
  }
  for(edge e: blue_edges){
    if(find_set(e.u) != find_set(e.v)){
      total_cost += e.weight;
      result[e.u].push_back(make_pair(e.v,e.weight));
      result[e.v].push_back(make_pair(e.u,e.weight));
      union_sets(e.u, e.v);
    }
  }
  
  edge se = special_edges[0];
  largest[se.u] = largest[se.v] = 0;
  dfs2(se.u);
  dfs2(se.v);
  total_cost += se.weight;  
  long long d = 20000;
  for(int i = 1;i < special_edges.size();i++){
    edge se2 = special_edges[i];
    d = min(d, se2.weight - max(largest[se2.u],largest[se2.v]));
  }
  cout << total_cost + d;
}