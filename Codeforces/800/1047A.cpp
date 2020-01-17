#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n;cin >> n;
  int d = n % 3;
  if(d == 2){
    cout << n - 3 << " " << 2 << " " << 1; 
  }else{
    cout << n - 2 << " " << 1 << " " << 1;
  }
}