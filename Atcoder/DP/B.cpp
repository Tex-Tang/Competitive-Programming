#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) { cout << #x << " = " << x << endl; }
typedef long long ll;
int main() { _
  int n,k;
  cin >> n >> k;
  int dp[n],a[n];
  for(int i = 0;i < n;i++){
    cin >> a[i];
    dp[i] = 0;
  }
  for(int i = 0;i < n;i++){
    int l = max(0, i - k);
    dp[i] = dp[l] + abs(a[i] - a[l]);
    for(int j = l + 1;j < i;j++){
      dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
    }
  }
  cout << dp[n - 1];
}