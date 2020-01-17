#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  cout << min(min(c*d, (k*l) / nl), p / np) / n;
}