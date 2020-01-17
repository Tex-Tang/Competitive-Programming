#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  int sum = 0;
  string s;cin>>s;
  for(int i = 0;i < n;i++){
    if(s[i] == '-') sum--;
    else sum++;
    if(sum < 0 && s[i] == '-'){
      sum = 0;
    }
  }
  cout << sum;
}