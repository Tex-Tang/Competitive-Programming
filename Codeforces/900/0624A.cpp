#include <bits/stdc++.h>

using namespace std;

int main(){
  double d,L,v1,v2;
  cin >> d >> L >> v1 >> v2;
  cout.precision(20);
  long double ans = (L - d)/(v1 + v2);
  cout << ans;
}