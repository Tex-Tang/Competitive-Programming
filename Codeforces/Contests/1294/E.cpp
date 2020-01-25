#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int arr[n][m];
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      cin >> arr[i][j];
      arr[i][j]--;
    }
  }
  int ans = 0;
  for(int j = 0;j < m;j++){
    int count[n];
    for(int i = 0;i < n;i++) count[i] = i + n;
    for(int i = 0;i < n;i++){
      int col = arr[i][j] % m;
      int row = arr[i][j] / m;
      //cout << i << " " << arr[i][j] << " "<< row << " " << col << endl;
      if(col == j){
        // i = standard row
        // row = current row
        if(row < n){
          if(i >= row){
            count[i - row]--;
          }else{
            count[n - (row - i)]--;
          }
        }
      }
    }
    int curr = count[0];
    for(int i = 0;i < n;i++){
      curr = min(curr, count[i]);
    }
    ans += curr;
  }
  cout << ans << endl;
}