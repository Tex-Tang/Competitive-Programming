#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n,x;cin >> n >> x;
  int sum = 0,z;
  for(int i = 0;i < n;i++){
    cin >> z;
    sum += z;
  }
  cout << abs(sum) / x + ((abs(sum) % x) ? 1 : 0);
}