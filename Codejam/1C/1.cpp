#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t = 1;t <= T;t++){
    int x,y;cin >> x >> y;
    string s;cin >> s;
    vector<pair<int,int>> path;
    path.resize(s.length() + 1);
    for(int i = 1;i <= s.length();i++){
      char d = s[i - 1];
      if(d == 'S'){ path[i]= {x,--y}; }
      if(d == 'N'){ path[i]= {x,++y}; }
      if(d == 'E'){ path[i]= {++x,y}; }
      if(d == 'W'){ path[i]= {--x,y}; }
    }
    int answer = -1;
    for(int c = 1;c <= s.length();c++){
      if(abs(path[c].first) + abs(path[c].second) <= c){
        answer = c;
        break;
      }
    }
    if(answer > 0){
      cout << "Case #" << t << ": " << answer << endl;
    }else{
      cout << "Case #" << t << ": IMPOSSIBLE"<< endl;
    }
  }
}