#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  int fb[100];
  fb[0] = 0;
  fb[1] = 1;
  for(int i = 2;i < 100;i++){
    fb[i] = fb[i - 2] + fb[i - 1];
  }
  string s = "";
  for(int i = 0;i < n;i++) s += 'o';
  for(int i = 1;fb[i] <= n;i++){
    s[fb[i] - 1] = 'O';
  }
  cout << s;
}