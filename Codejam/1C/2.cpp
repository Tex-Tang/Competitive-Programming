#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t = 1;t <= T;t++){
    double prob[10][26];
    for(int i = 0;i < 10;i++){
      for(int j = 0;j < 26;j++){
        prob[i][j] = 0.0;
      }
    }
    char answer[10];
    int u;cin >> u;
    for(int z = 0;z < 10000;z++){
      int m;cin >> m;
      string s;cin >> s;
      if(s.length() == 1){
        for(int j = 1;j <= min(m, 9);j++){
          prob[j][s[0] - 65] += 1/double(m);
        }
        continue;
      }
      int test = m - pow(10, s.length() - 1);
      if(s.length() < int(log10(m) + 1)){
        test = pow(10, s.length() - 1) - 1;
      }
      int k = test / pow(10, int(log10(test)));
      for(int j = 1;j <= k;j++){
        prob[j][s[0] - 65] += 1/double(k);
      }
      //cout << k << endl;
      for(int i = 1;i < s.length();i++){
        int total = test / pow(10,s.length() - 1 - i);
        int p = total / 10;
        //cout << p << " " << total << endl;
        //cout << s[i] << endl;
        int minx = total % 10;
        for(int j = 0;j < 10;j++){
          if(j <= minx){
            prob[j][s[i] - 65] += double(p + 1) / (total + 1);
          }
          if(j > minx){
            prob[j][s[i] - 65] += double(p) / (total + 1);
          }
        }
      }      
    }
    
    for(int i = 0;i < 10;i++){
      double maxx = 0, maxi = 0;
      for(int j = 0;j < 26;j++){
        if(prob[i][j] > maxx){
          maxi = j;
          maxx = prob[i][j];
        }
      }
      cout << char(65 + maxi);
    }
  }
}