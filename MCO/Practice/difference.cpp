#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  int m = -1001;
  vector<int> arr;
  int sum = 0;
  for(int i = 0;i < N;i++){
    int x;cin >> x;
    if(x < 0){
      arr.push_back(x);
    }
    m = max(m, x);
  }
  sort(arr.begin(),arr.end());
  for(int i = 0;i < arr.size() && i < K;i++){
    m -= arr[i];
  }
  cout << m << endl;
}