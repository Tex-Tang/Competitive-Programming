#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;cin >>n;
  int ans = 0,i = 1, j = 1;
  while(n - i >= 0){
    n -= i;
    j++;
    i+=j;
    ans++;
  }
  cout << ans;
}