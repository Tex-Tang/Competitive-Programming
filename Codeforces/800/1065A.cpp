#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;cin >> t;
  for(int p = 0;p < t;p++){
    long long s,a,b,c;
    cin >> s >> a >> b >> c;
    long long x = s / (a * c);
    cout << s / c + x * b << endl;
  }
}