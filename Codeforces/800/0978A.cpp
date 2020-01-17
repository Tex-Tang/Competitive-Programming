#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  vector <pair<int,int>> arr;
  int exist[1000];
  for(int i = 0;i < 1000;i++) exist[i] = -1;
  for(int i = 0;i < n;i++){
    int z;cin >> z;
    exist[z - 1] = i;
  }
  for(int i = 0;i < 1000;i++){
    if(exist[i] != -1) arr.push_back(make_pair(exist[i], i + 1));
  }
  cout << arr.size() << endl;
  sort(arr.begin(), arr.end());
  for(int i = 0;i < arr.size();i++){
    cout << arr[i].second << " ";
  }
}