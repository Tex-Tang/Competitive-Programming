#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;cin >> n;
  int lz = 0,lo = 0, rz = 0, ro = 0;
  for(int i = 0;i < n;i++){
    int l,r;
    cin >> l >> r;
    lz += l == 0;
    lo += l == 1;
    rz += r == 0;
    ro += r == 1;
  }
  cout << min(lz,lo) + min(rz,ro);
}