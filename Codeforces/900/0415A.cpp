#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n,m;
  cin >> n >> m;
  int b[m], a[n];
  for(int i = 0;i < n;i++) a[i] = -1;
  for(int i = 0;i < m;i++){
    cin >> b[i];
    for(int j = b[i] - 1;j < n;j++){
      if(a[j] == - 1) a[j] = b[i];
    }
  }
  for(int i = 0;i < n;i++) cout << a[i] << " ";

}