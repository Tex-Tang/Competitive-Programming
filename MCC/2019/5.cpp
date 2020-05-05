#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
  string str = "1011100111";
  int k = 3;
  int dp[str.length()];
  int n = str.length();
  for(int i = 0;i < n;i++){ dp[i] = 0; }
  int count = 0;
  int czero = 0;
  int index = 0;
  long long ans = 0;
  long long maxans = 0;
  for(int i = 0;i < n;i++){
    if(str[i] == '1'){
      count++;
    } else {
      dp[index] = count;
      count = 0;
      if(czero <= k){
        czero++;
      } else if(czero > k) {
        ans -= dp[index - k - 1];
      }
      ans += dp[index];
      maxans = max(maxans, ans);
      index++;
    }
  }
  dp[index] = count;
  if(czero > k) {
    ans -= dp[index - k - 1];
  }
  ans += dp[index];
  maxans = max(maxans, ans);
  cout << maxans;
}