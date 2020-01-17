#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int c[n], a[m];
  for(int i = 0;i < n;i++) cin >> c[i];
  for(int i = 0;i < m;i++) cin >> a[i];
  int j = 0,i = 0,t = 0;
  while(j < n && i < m){
    for(;j < n;j++){
      if(c[j] <= a[i]){
        i++;
        t++;
        break;
      }
    }
    j++;
  }
  cout << t;
}