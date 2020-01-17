#include <bits/stdc++.h>

using namespace std;

int main(){
  vector <int> arr;
  bool exist[100];
  for(int i = 0;i < 100;i++) exist[i] = false;
  int n;cin >> n;
  int k;cin >> k;
  for(int i = 0;i < n;i++){
    int z;cin >> z;
    if(exist[z - 1] == false){
      exist[z - 1] = true;
      arr.push_back(i + 1);
    }
  }
  if(arr.size() >= k){
    cout << "YES" << endl;
    for(int i = 0;i < k;i++){
      cout << arr[i] << " ";
    }
  }else{
    cout << "NO";
  }
}