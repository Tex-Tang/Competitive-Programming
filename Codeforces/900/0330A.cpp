#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n,m;
  cin >> n >> m;
  int arr[n][m];
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      char z;cin >> z;
      arr[i][j] = z == 'S';
    }
  }
  int ans = 0;
  for(int i = 0;i < n;i++){
    bool s = true;
    for(int j = 0;j < m;j++){
      if(arr[i][j]){
        s = false;
        break;
      }
    }
    if(s){
      for(int j = 0;j < m;j++) arr[i][j] = 2;
    }
  }
  for(int i = 0;i < m;i++){
    bool s = true;
    for(int j = 0;j < n;j++){
      if(arr[j][i] == 1){
        s = false;
        break;
      }
    }
    if(s){
      for(int j = 0;j < n;j++) arr[j][i] = 2;
    }
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      if(arr[i][j] == 2){
        ans++;
      }
    }
  }
  cout << ans;
}