#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int N, M;
int minDistance(int dist[], bool sptSet[]) 
{ 
    int min = INT_MAX, min_index; 
    for (int v = 0; v < N; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
}
int main(){
  ifstream fin("loan.in");
  ofstream fout("loan.out");
 
  cin >> N >> M;
  int p[N + 1];
  for(int i = 1;i <= N;i++) cin >> p[i];
  int graph[N + 1][N + 1];
  for(int i = 1;i <= N;i++)
    for(int j = 1;j <= N;j++)
      graph[i][j] = 0;
  
  for(int i = 0;i < M;i++){
    int a,b,w;
    cin >> a >> b >> w;
    graph[a][b] = w;
    graph[b][a] = w;
  }

  int maxn = -1;
  for(int i = 1;i <= N;i++){
    if(p[i] != i){
      int dist[N];
      bool sptSet[N];
      for (int j = 0; j < N; j++) 
        dist[j] = INT_MAX, sptSet[j] = false; 
      
      dist[i] = 0; 
      
      for (int count = 0; count < N - 1; count++) { 
          int u = minDistance(dist, sptSet); 
          sptSet[u] = true; 
          for (int v = 0; v < N; v++) 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && max(dist[u],graph[u][v]) < dist[v]) 
                dist[v] = max(dist[u],graph[u][v]); 
      }
      for (int i = 1; i <= N; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
      maxn = max(maxn, dist[p[i]]);
    }
  }
  cout << maxn;
}