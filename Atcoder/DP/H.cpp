#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main(){
  int row, col;
  cin >> row >> col;
  bool grid[row][col];
  for(int i = 0;i < row;i++){
    for(int j = 0;j < col;j++){
      char c;cin >> c;
      grid[i][j] = c == '#';
    }
  }
  
  long long dp[row + 1][col + 1];
  
  for(int i = 0;i <= row;i++){
    for(int j = 0;j <= col;j++){
      dp[i][j] = 0;
    }
  }
  for(int i = 1;i <= row;i++){
    for(int j = 1;j <= col;j++){
      if(i == 1 && j == 1) dp[i][j] = 1;
      else if(!grid[i - 1][j - 1]) dp[i][j] = ((dp[i - 1][j] % MOD) + (dp[i][j - 1] % MOD)) % MOD;
    }
  }
  cout << dp[row][col] % MOD;
}
