#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;cin >> T;
  for(int t = 0;t < T;t++){
    int n;cin >> n;
    cout << (1 << n) - ((1 << n) - (1 << (n - n /2))) + (1 << (n - n /2)) - 2 << endl;
  }
}