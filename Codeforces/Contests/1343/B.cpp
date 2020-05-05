#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;cin >> T;
  for(int t = 0;t < T;t++){
    int n;cin >> n;
    if((n / 2) % 2 == 1){
      cout << "NO" << endl;
      continue;
    }else{
      cout << "YES" << endl;
    }
    long long sum = 0;
    for(int i = 1;i <= n / 2;i++){
      cout << 2*i << " ";
      sum += 2*i;
    }
    for(int i = 0;i < n / 2 - 1;i++){
      cout << 1 + 2*i << " ";
      sum -= 1 + 2*i;
    }
    cout << sum << endl;
  }
}