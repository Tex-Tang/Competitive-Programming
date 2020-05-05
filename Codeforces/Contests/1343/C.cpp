#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;cin >> T;
  for(int t = 0;t < T;t++){
    int n;cin >> n;
    long long dp[n][n][2];
    long long a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    bool positive = a[0] > 0;
    long long sum = 0;
    long long minx = -10e9 - 1;
    long long maxx = -10e9 - 1;
    for(int i = 0;i < n;i++){
      if(a[i] > 0 && positive){
        maxx = max(a[i], maxx);
      }else if(a[i] > 0 && !positive){
        sum += minx;
        minx = - 10e9 - 1;
        positive = true;
        maxx = max(a[i], maxx);
      }else if(a[i] < 0 && !positive){
        minx = max(a[i],minx);
      }else{
        sum += maxx;
        maxx = -10e9 - 1;
        positive = false;
        minx = max(a[i], minx);
      }
    }
    if(positive){ sum += maxx; }
    else{ sum += minx; }
    cout << sum << endl;
  }
}
