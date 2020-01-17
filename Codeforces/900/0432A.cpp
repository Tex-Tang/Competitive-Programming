#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n,k;
  cin >> n >> k;
  int y[n];
  for(int i = 0;i < n;i++) cin >> y[i];
  sort(y, y + n);
  int sum = 0;
  for(int i = 0;i < n;i++){
    if(5 - y[i] >= k) sum++;
  }
  cout << sum / 3;
}