#include <bits/stdc++.h>

using namespace std;

int main(){
  int N;cin >> N;
  double p[N];
  double dp[N + 1][N];
  for(int i = 0;i < N;i++){
    cin >> p[i];
    
  }
  for(int i = 0;i <= N;i++)
    for(int j = 0;j < N;j++) 
      dp[i][j] = 0;
  dp[0][0] = 1 - p[0];
  dp[1][0] = p[0];
  for(int i = 1;i < N;i++){
    dp[0][i] = (1 - p[i])*dp[0][i - 1];
    for(int j = 1;j <= i + 1;j++){
      dp[j][i] = p[i]*dp[j - 1][i - 1] + (1 - p[i])*dp[j][i - 1];
    }
  }

  double answer = 0;
  for(int i = N/2 + 1;i <= N;i++){
    answer += dp[i][N - 1];
  }
  cout << setprecision(10);
  cout << answer;
}