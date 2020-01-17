#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  if(n <= 9){
    cout << 1 << endl;
    cout << n;
  }else{
    cout << n << endl;
    for(int i = 0;i < n;i++){
      cout << 1 << " ";
    }
  }
}