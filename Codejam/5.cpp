#include <bits/stdc++.h>

using namespace std;
std::ofstream outfile;

  
vector <int> path_r;
void dfs(int n, int k, int u, bool visited[], bool visited2[], bool second, int sum, vector<int> path){
  path.push_back(u);
  
  if(path.size() == 2*n){
    for(auto i:path){
    outfile << i << " ";
  }
  outfile << endl;
    if(sum == k) path_r = path;
  }else{
    if(!second){
      visited2[u] = true;
      for(int i = 1;i <= n;i++){
        if(!visited[i]){
          bool _visited[55], _visited2[55];
          copy(visited, visited + 55, _visited);
          copy(visited2, visited2 + 55, _visited2);
          dfs(n, k, i, _visited, _visited2, !second, sum , path);
        }
      }
    }else{
      visited[u] = true;
      for(int i = 1;i <= n;i++){
        if(!visited2[i]){
          bool _visited[55], _visited2[55];
          copy(visited, visited + 55, _visited);
          copy(visited2, visited2 + 55, _visited2);
          dfs(n,k, i, _visited, _visited2, !second, sum + (u + i - 2) % n + 1, path);
        }
      }
    }
  }

}

int main(){
  outfile.open("test.txt", std::ios_base::app);
  int T;cin >> T;
  for(int t = 1;t <= T;t++){
    int n,k;
    cin >> n >> k;
    bool visited[55], visited2[55];
    for(int i = 1;i <= n;i++){
      visited2[i] = visited[i] = false;
    }
    dfs(n,k,1,visited, visited2, true, 0, vector<int>{});
    
    cout << "Case #" << t << ": ";
    if(path_r.size() == 2*n){
      cout << "POSSIBLE" << endl;
      int row[n], col[n];
      for(int i = 0;i < 2*n;i += 2){
        row[i / 2] = path_r[i] - 1;
        col[i / 2] = path_r[i + 1] - 1;
      }
      int matrix[n][n];
      for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
          cout << (row[i] + col[j]) % n + 1 << " ";
        }
        cout << endl;
      }
    }else{
      cout << "IMPOSSIBLE" << endl;
    }
    path_r.clear();
  }
}