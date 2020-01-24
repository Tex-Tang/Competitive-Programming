#include <bits/stdc++.h>
#include <fstream>

using namespace std;
ifstream fin("milkvisits.in");
ofstream fout("milkvisits.out");

void dfs(bool visited[], vector<int>graph[],int cows[], bool check[2], int x, int y, int z){ 
  check[cows[x]] = true;
  visited[x] = true;
  if(x == y){
    fout << check[z];
    return;
  }
  int flag = 0; 
  for(int i = 0;i < graph[x].size();i++){
    int v = graph[x][i];
    if(!visited[v]){
      dfs(visited, graph, cows, check, v, y, z);
      flag = 1;
    }
  }
  if(flag == 0){
    check[cows[x]] = false;
  }
}
int main(){
  
  int n,m;
  fin >> n >> m;
  int cows[n];
  for(int i = 0;i < n;i++){
    char c;
    fin >> c;
    cows[i] = c == 'H';
  }
  vector <int> graph[n];
  for(int i = 0;i < n - 1;i++){
    int x, y;
    fin >> x >> y;
    graph[x - 1].push_back(y - 1);
    graph[y - 1].push_back(x - 1);
  }

  for(int i = 0;i < m;i++){
    bool cowsx[2] = { false, false };
    bool visited[n];
    for(int j = 0;j < n;j++){ visited[j] = false; }
    int x, y, z;
    char c;
    fin >> x >> y >> c;
    z = c == 'H';
    dfs(visited,graph,cows,cowsx,x - 1, y - 1, z);
  }
}