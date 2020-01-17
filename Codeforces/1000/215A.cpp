#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin >> n;
  int arr1[n];
  for(int i = 0;i < n;i++) cin >> arr1[i];
  cin >> m;
  int arr2[m];
  int max = 0, maxi = -1;
  for(int i = 0;i < m;i++) cin >> arr2[i];
  for(int i = 0;i < m;i++){
    for(int j = 0;j < n;j++){
      if(arr2[i] % arr1[j] == 0){
        if(arr2[i] / arr1[j] == max){
          maxi++;
        }else if(arr2[i] / arr1[j] > max){
          max = arr2[i] / arr1[j];
          maxi = 1;
        }
      }
    }
  }
  cout << maxi;
}