#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  int sum = 0;
  for(int i = 0;i < n;i++){
    int z;cin >> z;
    sum += abs(z);
  }
  cout << sum;
}