#include <bits/stdc++.h>
#include <fstream>

using namespace std;
 
int main(){
  int n,l, sum = 0;
  cin >> n >> l;
  pair <int ,pair <int,int> > arr[n];
  for(int i = 0;i < n;i++){
    cin >> arr[i].second.first;
    cin >> arr[i].first;
    cin >> arr[i].second.second;
    sum += arr[i].second.first;
  }
  int ssum = 0, ans = 0;
  int i = 0, j = n - 1;
  sort(arr, arr + n);
  while(arr[i].second.second == -1){
    ssum += arr[i].second.first;
    i++;
  }
  while(arr[j].second.second == 1){
    ssum += arr[j].second.first;
    j--;
  }
  while(ssum < sum / 2){
    sort(arr, arr + n);
    
    while(arr[i].second.second == -1){
      ssum += arr[i].second.first;
      i++;
    }
    while(arr[j].second.second == 1){
      ssum += arr[j].second.first;
      j--;
    }
    vector <int> right,left;
    for(int x = i;x < j - 1;x++){
      if(arr[x].second.second == -1 && arr[x + 1].second.second == 1){
        arr[x].second.second = -1;
        left.push_back(x);
        arr[x + 1].second.second = 1;
        right.push_back(x + 1)
        ans++;
      }
    }


  }
  cout << ans;

}

