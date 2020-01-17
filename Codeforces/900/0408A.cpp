#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;cin >> n;
  int arr[n];
  for(int i = 0;i < n;i++) cin >> arr[i];
  int minx = 10e5 + 1;
  for(int i = 0;i < n;i++){
    int sum = arr[i]*15;
    for(int j = 0;j < arr[i];j++){
      int z;cin >> z;
      sum += z*5;
    }
    minx = min(sum, minx);
  }
  cout << minx;
}