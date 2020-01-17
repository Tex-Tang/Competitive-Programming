#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  
  while(n > 1){
    int x = log2(n) + 1; 
    cout << x << " ";
    n -= 1 << (x - 1);
  }
  cout << (n == 1 ? "1" : "");
}