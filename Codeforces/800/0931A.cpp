#include <bits/stdc++.h>

using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int d = abs(b - a);
  int c = 0;
  if(d % 2 == 0){
    cout << (d / 2)*(d / 2 + 1);
  }else{
    cout << ((d / 2)*(d / 2 + 1) / 2) + ((d / 2 + 1)*(d / 2 + 2) / 2);
  }
}