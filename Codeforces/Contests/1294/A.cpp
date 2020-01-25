#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int i = 0;i < t;i++){
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    int m = max(a, max(b,c));
    int k = m - a + m - b + m - c;
    if((n - k) % 3 == 0 && (n - k) >= 0){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}