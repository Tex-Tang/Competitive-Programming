#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int year;cin >> year;
  for(int i = year + 1;i < 10000;i++){
    int f = i / 1000;
    int s = i % 1000 / 100;
    int t = i % 100 / 10;
    int z = i % 10;
    if(f != s && s != t && t != z && z != f && f != t && s != z){
      cout << i;
      return 0;
    }
  }
}