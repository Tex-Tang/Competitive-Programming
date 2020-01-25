#include <bits/stdc++.h>

using namespace std;
int mods[400005];
int main(){
  int q, x;
  cin >> q >> x;
  int p = 0;
  for(int i = 0;i < q;i++){
    int y;
    cin >> y;
    mods[y % x]++;
    while(mods[p % x]){
      mods[p % x]--;
      p++;
    }
    cout << p << endl;
  }
}