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
vector<vector< pair<int,long long>>> result_red;
vector<vector< pair<int,long long>>> result_blue;

vector<int> largest;
vector<int> parent;
vector<int> ranks;
vector<vector< pair<int,long long>>> result;
vector <int> color;
vector <pair<int,int>> parents;
int cycle_start,cycle_end;


bool dfs(int v){
  color[v] = 1;
  for(pair<int,int> p: result[v]){
    int u = p.first;
    if(u != parents[v].first){
      if(color[u] == 0){
        parents[u] = make_pair(v,p.second);
        if(dfs(u)){
          return true;
        }
      }else if(color[u] == 1){
        cycle_start = u;
        cycle_end = v;
        parents[u] = make_pair(v,p.second);
        return true;
      }
    }
  }
  color[v] = 2;
  return false;
}

long long get_highest_cost_edge(){
  color.assign(N + 1, 0);
  parents.assign(N + 1, make_pair(-1,-1));
  cycle_start = -1;
  for(int i = 1;i <= N;i++){
    if(color[i] == 0 && dfs(i)) break;
  }
  if(cycle_start == -1) return -1;
  else{
    long long maxm = 0;
    int u = cycle_start;
    do{
      pair<int,long long> v = parents[u];
      maxm = max(maxm, v.second);
      u = v.first;
    }while(u != cycle_start);
    return maxm;
  }
}

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