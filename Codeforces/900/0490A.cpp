#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int w;cin >> w;
  vector<int> arr[3];
  for(int i = 0;i < w;i++){
    int z;cin >> z;
    arr[z - 1].push_back(i + 1);
  }
  int d = min(arr[0].size(), min(arr[1].size(), arr[2].size()));
  cout << d << endl;
  for(int i = 0;i < d;i++){
    for(int j = 0;j < 3;j++){
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }

}