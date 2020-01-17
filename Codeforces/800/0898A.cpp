#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n;cin >> n;
  if(n % 10 > 4){
    cout << n - n % 10 + 10;
  }else{
    cout << n - n % 10;
  }
}