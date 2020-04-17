  #include <bits/stdc++.h>

  using namespace std;

  int main(){
    int cases;cin >> cases;
    for(int z = 1;z <= cases;z++){
      int n;cin >> n;
      pair <int,pair<int,int>> arr[n];
      
      for(int i = 0;i < n;i++){
        int s,e;cin >> s >> e;
        arr[i] = make_pair(s,make_pair(e,i));
      }
      sort(arr, arr + n);
      int c = arr[0].second.first,j = arr[1].second.first;
      string s;
      s.resize(n);
      s[arr[0].second.second] = 'C';
      s[arr[1].second.second] = 'J';
      for(int i = 2;i < n;i++){
        if(c <= arr[i].first){
          s[arr[i].second.second] = 'C';
          c = arr[i].second.first;
        }else if(j <= arr[i].first){
          s[arr[i].second.second] = 'J';
          j = arr[i].second.first;
        }else{
          s = "IMPOSSIBLE";
          break;
        }
      }
      cout << "Case #" << z << ": "<< s << endl;
    }
  }