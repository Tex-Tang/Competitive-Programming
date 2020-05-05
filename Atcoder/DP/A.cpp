#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) { cout << #x << " = " << x << endl; }
typedef long long ll;
int main() { _
  int n;
  cin >> n;
  int dp[n],a[n];
  for(int i = 0;i < n;i++){
    cin >> a[i];
    dp[i] = 0;
  }
  dp[0] = 0;
  dp[1] = abs(a[0] - a[1]);
  for(int i = 2;i < n;i++){
    dp[i] += min(dp[i - 1] + abs(a[i] - a[i - 1]),dp[i - 2] + abs(a[i] - a[i - 2]));
  }
  cout << dp[n - 1];
}
