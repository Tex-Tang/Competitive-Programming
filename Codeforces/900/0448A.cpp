#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int a1,a2,a3,b1,b2,b3;
  cin >> a1 >> a2 >> a3;
  cin >> b1 >> b2 >> b3;
  int n;cin >> n;
  int d = (int)ceil((double)(a1 + a2 + a3) / 5) + (int)ceil((double)(b1 + b2 + b3) / 10);
  cout << ((d <= n) ? "YES" : "NO");
  
}