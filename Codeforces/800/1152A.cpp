#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;cin >> n >> m;
  int nood = 0, mood = 0;
  for(int i = 0;i < n;i++){
    int z;cin >> z;
    if(z % 2 == 1){
      nood++;
    }
  }
  for(int i = 0;i < m;i++){
    int z;cin >> z;
    if(z % 2 == 1){
      mood++;
    }
  }
  cout << min(nood, m - mood) + min(n - nood, mood);
}