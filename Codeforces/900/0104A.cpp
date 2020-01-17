#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;cin >> n;
  n -= 10;
  if(n > 11 || n <= 0){
    cout << 0;
  }else{
    if(n == 10){ cout << 15; }
    else{ cout << 4 ; }
  }
}