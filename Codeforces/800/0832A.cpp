#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n,k;
  cin >> n >> k;
  if((n / k) % 2 == 1){
    cout << "YES";
  }else{
    cout << "NO";
  }
}