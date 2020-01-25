#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int i = 0;i < t;i++){
    int n;
    cin >> n;
    pair<int,int> arr[n];
    for(int i = 0;i < n;i++){
      int x, y;
      cin >> x >> y;
      arr[i] = make_pair(x,y);
    }
    sort(arr, arr + n);
    int xs = 0;
    int ys = 0;
    string s = "";
    bool flag = true;
    for(int i = 0;i < n;i++){
      if(arr[i].first >= xs && arr[i].second >= ys){
        for(int x = arr[i].first - xs;x > 0;x--) s += "R";
        for(int y = arr[i].second - ys;y > 0;y--) s += "U";
        xs = arr[i].first;
        ys = arr[i].second;
      }else{
        cout << "NO" << endl;
        flag = false;
        break;
      }
    }
    if(flag){
      cout << "YES" << endl;
      cout << s << endl;
    }

  }
}