#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;cin >> t;
  for(int i = 0;i < t;i++){
    int l,r;cin >> l >> r;
    bool found = false;
    for(int x = l;x <= r;x++){
      if(x*2 <= r){
        cout << x << " " << x*2 << endl;;
        break;
      }
    }
  }
}