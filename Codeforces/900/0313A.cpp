#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  long long n;cin >> n;
  if(n >= 0){
    cout << n;
  }else{
    string s = to_string(abs(n));
    int j = s.length() - 1,i = s.length() - 2;
    if(s[i] > s[i + 1]){
      j = i;
    }
    s.erase(j, 1);
    if(s[0] == '0'){
      cout << s;
    }else{
      cout << '-' << s;
    } 
  }
}