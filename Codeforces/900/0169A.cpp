#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n,a,b;
  cin >> n >> a >> b;
  int h[n];
  for(int i = 0;i < n;i++) cin >> h[i];
  sort(h , h + n);
  cout << h[b] - h[b - 1];
}