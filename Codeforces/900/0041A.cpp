#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  string o,s;
  cin >> o;
  cin >> s;
  reverse(s.rbegin(), s.rend());
  if(o == s){
    cout << "YES";
  }else{
    cout << "NO";
  }
}