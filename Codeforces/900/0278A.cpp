#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;cin >> n;
  int arr[n], sum = 0;
  for(int i = 0;i < n;i++){ cin>>arr[i];sum += arr[i]; }
  int s,t;cin >> s >> t;
  int ans = 0;
  for(int i = min(s - 1, t - 1);i < max(s - 1, t - 1);i++){
    ans += arr[i];
  }
  cout << min(ans, sum - ans);
}