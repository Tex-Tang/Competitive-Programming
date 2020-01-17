#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  string s;cin >> s;
  int one = 0,zero = 0;
  for(int i = 0;i < n;i++){
    if(s[i] == '0') zero++;
    else one++;
  }
  if(one != zero){
    cout << 1 << endl;
    cout << s;
  }else{
    cout << 2 << endl;
    cout << s[0] << " " << s.substr(1,s.length() - 1);
  }

}