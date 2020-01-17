#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  bool g[n][n];
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      char z; cin >> z;
      g[i][j] = z == 'X';
    }
  }
  int sum = 0;
  for(int i = 1;i < n - 1;i++){
    for(int j = 1;j < n - 1;j++){
      if(g[i][j] && g[i - 1][j - 1] && g[i - 1][j + 1] && g[i + 1][j - 1] && g[i + 1][j + 1]){
        sum++;
      }
    }
  }
  cout << sum;
}