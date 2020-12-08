#include <bits/stdc++.h>
using namespace std;
ifstream infile("string.txt");
int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  string S;
  getline(infile, S);
  int K = 96;
  int n = S.length();
  int dp[K][n][2];
/*
  for(int i = 0;i < K;i++)
    for(int j = 0;j < n;j++)
      dp[i][j][0] = dp[i][j][1] = 0;

  for(int i = 0;i < n;i++) dp[0][i][0] = dp[0][i][1] = 1;
  for(int l = 1;l < K;l++){
    int num[26][2];
    for(int i = 0;i < 26;i++) num[i][0] = num[i][1] = 0;
    for(int i = l;i < n;i++){
      dp[l][i][0] = 0;
      dp[l][i][1] = 0;
      num[int(S[i - 1]) - 97][0] += dp[l - 1][i - 1][0];
      num[int(S[i - 1]) - 97][1] += dp[l - 1][i - 1][1];
      for(int j = 0;j < int(S[i]) - 97;j++){
        dp[l][i][1] += num[j][0] % 1000;
      }
      for(int j = int(S[i]) - 97 + 1; j < 26;j++){
        dp[l][i][0] += num[j][1] % 1000;
      }
      //for(int j = l - 1;j < i;j++){
      //  if(S[j] > S[i]) dp[l][i][1] += (dp[l - 1][j][0] % 1000);
      //  if(S[j] < S[i]) dp[l][i][0] += (dp[l - 1][j][1] % 1000);
      //}
    }
  }*/
  long long sum = 0;
  //for(int i = K - 1;i < n;i++){
    //sum += dp[K - 1][i][0];
    //sum += dp[K - 1][i][1];
  //}
  cout << sum % 1000;
  
}