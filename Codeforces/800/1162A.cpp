#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,h,m;
  cin >> n >> h >> m;
  int arr[n], sum = 0;;
  for(int i = 0;i < n;i++) arr[i] = h;
  for(int i = 0;i < m;i++){
    int l,r,x;
    cin >> l >> r >> x;
    for(int j = l;j <= r;j++){
      arr[j - 1] = min(arr[j - 1], x);
    }
  }
  for(int i = 0;i < n;i++) sum += arr[i]*arr[i];
  cout << sum;
}