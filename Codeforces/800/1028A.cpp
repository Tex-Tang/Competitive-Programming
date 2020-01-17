#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  int m;cin >> m;
  bool arr[n][m];
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      char c; cin >> c;
      arr[i][j] = c == 'B';
    }
  }
  int x = 0, cx = -1, y = 0, cy = -1;
  bool found = false;
  for(int i = 0;i < n && found == false;i++){
    for(int j = 0;j < m;j++){
      if(arr[i][j]){
        x++;
      }
      if(!arr[i][j] && x != 0){
        cx = j - x/2 - 1;
        found = true;
        break;
      }
      if(j == m - 1 && x != 0){
        cx = j - x/2;
        found = true;
        break;
      }
    }
  }
  for(int i = 0;i < n;i++){
    if(arr[i][cx]){
      y++;
    }
    if(!arr[i][cx] && y != 0){
      cy = i - y/2 - 1;
      break;
    }
    if(i == n - 1 && x != 0){
      cy = i - y/2;
      break;
    }
  }
  cout << cy + 1 << " " << cx + 1 ;
}