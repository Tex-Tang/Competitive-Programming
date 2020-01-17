#include <bits/stdc++.h>

using namespace std;

int main(){
  int q;cin >> q;
  for(int i = 0;i < q;i++){
    long long z;cin>>z;
    int ans = 0;
    while(z != 1){
      if(z % 2 == 0){
        z = z/2;
        ans++;
      }else if(z % 3 == 0){
        z = z * 2 / 3;
        ans++;
      }else if(z % 5 == 0){
        z = z * 4 / 5;
        ans++;
      }else{
        ans = -1;
        break;
      }
    }
    cout << ans << endl;
  }
}