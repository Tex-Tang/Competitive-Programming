#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  int arr[n];
  int nmax = 0;
  int sum = 0;
  for(int i = 0;i < n;i++){
    cin >> arr[i];
    nmax = max(arr[i], nmax);
    sum += arr[i];
  }
  while(nmax*n - sum <= sum){
    nmax++;
  }
  cout << nmax;
}