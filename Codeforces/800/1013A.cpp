#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  int s1 = 0,s2 = 0;
  for(int i = 0,z;i < n;i++) cin >> z, s1+=z;
  for(int i = 0,z;i < n;i++) cin >> z, s2+=z;
  if(s2 > s1){
    cout << "NO";
  }else{
    cout << "YES";
  }
}