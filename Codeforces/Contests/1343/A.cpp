#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;cin >> T;
  for(int t = 0;t < T;t++){
    long long n;cin >> n;
    for(int i = 2;i <= 32;i++){
      long long x = n / ((1 << i) - 1);
      if(x * ((1 << i) - 1) == n){
        cout << x << endl;
        break;
      }
    }
  }
}