#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
  ifstream fin("measurement.in");
  ofstream fout("measurement.out");
  int n;
  fin >> n;
  int cows[3] = {7,7,7};
  pair< int,pair<int,int> > arr[n];
  for(int i = 0;i < n;i++){
    int z;
    fin >> arr[i].first;
    string x;
    fin >> x;
    if(x[0] == 'M') arr[i].second.first = 0;
    if(x[0] == 'E') arr[i].second.first = 1;
    if(x[0] == 'B') arr[i].second.first = 2;
    string y;
    fin >> y;
    arr[i].second.second = stoi(y);
  }
  sort(arr, arr + n);
  int mx = 7, ans = 0;
  bool board[3] = { false, false, false };
  for(int i = 0;i < n;i++){
    cows[arr[i].second.first] += arr[i].second.second;
    mx = max(cows[0], max(cows[1], cows[2]));
    bool cboard[3] = { false, false, false };
    for(int i = 0;i < 3;i++) cboard[i] = cows[i] == mx;
    if(cboard[0] != board[0] || cboard[1] != board[1] || cboard[2] != board[2]){
      ans++;
      board[0] = cboard[0];
      board[1] = cboard[1];
      board[2] = cboard[2];
    }
  }
  fout << ans;
}