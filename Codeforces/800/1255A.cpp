#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int t;cin >> t;
  for(int p = 0;p < t;p++){
    long long a,b;cin >> a >> b;
    int d = abs(b - a);
    int x = d % 5;
    if(x == 0){
      cout << d / 5 << endl;
    }else if(x == 1){
      cout << d / 5 + 1 << endl;
    }else if(x == 2){
      cout << d / 5 + 1 << endl;
    }else if(x == 3){
      cout << d / 5 + 2 << endl;
    }else if(x == 4){
      cout << d / 5 + 2 << endl;
    }
  }
}