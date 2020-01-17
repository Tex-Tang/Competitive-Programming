#include <bits/stdc++.h>

using namespace std;

int main(){
  int x,y,z,t1,t2,t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int s = abs(x - y) * t1;
  int e = (abs(x - z) * t2) + t3*3 + (abs(x - y) * t2);
  if(e <= s){
    cout << "YES";
  }else{
    cout << "NO";
  }
}