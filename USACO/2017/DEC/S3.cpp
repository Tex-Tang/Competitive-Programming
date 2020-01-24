#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dfs(vector <int> graph[], int v){
  for(int i = 0;i < graph[v].size();i++){
    if(graph[v][i] == root){
      dfs(graph, graph[v][i]);
    }
  }
}

int find(int parent[], int x){
  if(parent[x] == -1){
    return x;
  }
  return find(parent, parent[x]);
}

int main(){
  int n;
  cin >> n;
  vector <int> graph[n];
  for(int i = 0;i < n;i++){
    int z;cin >> z;
    
    graph[i].push_back(z - 1);
  }

  int parent[n];
  for(int i = 0;i < n;i++) parent[i] = -1;

}