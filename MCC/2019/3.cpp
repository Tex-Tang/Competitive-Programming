#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
  string arr[] = {"even", "odd", "odd", "odd", "odd", "even", "even", "odd", "odd", "even", "even", "odd", "even", "even", "even", "even", "even", "even", "even", "odd", "odd", "even", "odd", "odd", "even", "odd", "odd", "even", "even", "odd", "odd", "even", "even", "odd", "odd", "odd", "odd", "even", "even", "odd", "even", "odd", "odd", "odd", "odd", "even", "odd", "even", "even", "even", "even", "even", "even", "odd", "odd", "odd", "odd", "even", "odd", "odd"};
  int n = sizeof(arr) / sizeof(arr[0]);
  long long ans = (arr[0] == "even") ? 1 : 2;
  
  for(int i = 1;i < n;i++){
    if(arr[i] == "odd"){
      long long z = pow(2, i);
      ans += z;
    }
  }
  cout << ans;
}

/*
1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
even
1,3,5,7,9,11,13,15,17,19
odd
3,7,11,15,19
odd
7,15
odd
15
*/