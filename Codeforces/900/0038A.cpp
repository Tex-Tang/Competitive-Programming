#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;cin >> n;
  int arr[n];
  for(int i = 0;i < n - 1;i++) cin >> arr[i];
  int a,b,s = 0;cin >> a >> b;
  for(int i = a;i < b;i++){
    s += arr[i - 1];
  }
  cout << s;
}