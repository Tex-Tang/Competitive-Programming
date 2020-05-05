#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;cin >> T;
  for(int t = 0;t < T;t++){
    int n,k;cin >> n >> k;
    set<int> a;
    for(int i = 0;i < n;i++){
      int b;cin >> b;
      a.insert(b);
    }
    if(a.size() > k){
      cout << -1 << endl;
      continue;
    }
    for(int i = 1;i <= n && a.size() < k;i++){
      a.insert(i);
    }
    cout << n*a.size() << endl;
    for(int i = 0;i < n;i++){
      for(int z: a){
        cout << z << " ";
      }
    }
    cout << endl;
  }
}