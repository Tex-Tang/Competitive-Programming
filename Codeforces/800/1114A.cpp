#include <bits/stdc++.h>

using namespace std;

int main(){
  int x,y,z,a,b,c;
  cin >> x >> y >> z;
  cin >> a >> b >> c;
  if(a >= x && a - x + b >= y && a + b + c - x - y >= z){
    cout << "YES";
  }else{
    cout << "NO";
  }
}