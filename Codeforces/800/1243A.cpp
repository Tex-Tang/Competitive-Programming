#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int t;cin >> t;
  for(int p = 0;p < t;p++){
    int n;cin >> n;
    int arr[n + 1];
    for(int i = 0;i <=n;i++) arr[i] = 0;
    for(int i = 0;i < n;i++){
      int z;cin >> z;
      for(int j = z;j > 0;j--){
        arr[j]++;
      }
    }
    for(int i = n;i > 0;i--){
      if(arr[i] >= i){
        cout << i << endl;
        break;
      }
    }
  }
}