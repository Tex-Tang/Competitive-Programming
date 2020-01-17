#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  int arr[n];
  for(int i = 0;i < n;i++){
    cin >> arr[i];
    arr[i] -= 1;
  }
  for(int i = 0;i < n;i++){
    if(arr[arr[arr[i]]] == i && arr[arr[i]] != arr[arr[arr[i]]] && arr[arr[i]] != i && arr[i] != i){
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}