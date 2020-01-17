#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;cin >> n;
  int arr[n];
  int minx = 1000, mini = -1, maxx = -1, maxi = -1;
  for(int i = 0;i < n;i++){
    int z = 0;cin >> z;
    arr[i] = z;
    if(z <= minx){
      minx = z;
      mini = i;
    }
    if(z > maxx){
      maxx = z;
      maxi = i;
    }
  }
  int ans = 0;
  while(mini != n - 1){
    arr[mini] = arr[mini + 1];
    arr[mini + 1] = minx;
    if(mini + 1 == maxi) maxi = mini;
    mini++; 
    ans++;
  }
  while(maxi != 0){
    arr[maxi] = arr[maxi - 1];
    arr[maxi - 1] = maxx;
    maxi--;
    ans++;
  }
  cout << ans;
}