#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  for(int i = 0;i < n;i++){
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int a = min(l1, r1);
    int b = min(l2, r2) == a ? max(l2, r2) : min(l2, r2);
    cout << a << " " << b << endl;
  }
}