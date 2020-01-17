#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int t;cin >> t;
  for(int i = 0;i < t;i++){
    int a,b,c;cin >> a >> b >> c;
    cout << min(b, c / 2)*3 + min(a, (b - min(b, c / 2))/2)*3 << endl;
  }
}