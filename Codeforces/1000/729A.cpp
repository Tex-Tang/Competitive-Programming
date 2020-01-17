#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  string s, ans = "";
  cin >> s;
  for(int i = 0;i < n;i++){
    if(s[i] != 'o' && s[i] != 'g'){
      ans += s[i];
    }else{
      int j = i;
      while(j < n - 2){
        if((j - i) % 2 == 0 && s[j] == 'o' && s[j + 1] == 'g' && s[j + 2] == 'o'){
          j += 2;
        }else{
          break;
        }
      }
      if(j == i){
        ans += s[i];
      }else{
        i = j;
        ans += "***";
      }
    }
  }
  cout << ans;
}