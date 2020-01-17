#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;cin >> n;
  int arr[n];
  for(int i = 0;i < n;i++) arr[i] = 0;
  int j = 0;
  for(int i = 1;i < n;i++){
    j += i;
    if(j > n - 1){
      j -= n;
    }
    cout << j + 1 << " ";
  }
}