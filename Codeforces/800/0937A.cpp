#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  set<int> a;
  for(int i = 0;i < n;i++){
    int z;cin >> z;
    if(z != 0){
      a.insert(z);
    }
  }
  cout << a.size();
  
}