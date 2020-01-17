#include <bits/stdc++.h>

using namespace std;

int main(){
  int K;
  cin >> K;
  int arr[K];
  int amax = 0;
  for(int i = 0;i < K;i++){
    cin >> arr[i];
    amax = max(amax, arr[i]);
  }
  cout << ((amax - 25) > 0 ? amax - 25 : 0);
}