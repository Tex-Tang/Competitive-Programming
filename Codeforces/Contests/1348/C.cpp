#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t = 0;t < T;t++){
    int k,n;cin >> n >> k;
    string str;
    cin >> str;
    sort(str.begin(), str.end());

    if(str[0] != str[k - 1]){
      cout << str[k-1] << endl;
      continue;
    }

    
    cout << str[0];
    if(str[k] != str[n - 1]){
      for(int i = k;i < n;i++){
        cout << str[i];
      }
    }else{
      for(int i = k;i < n;i+=k){
        cout << str[i];
      }
    }
    cout << endl;
  }
}
  