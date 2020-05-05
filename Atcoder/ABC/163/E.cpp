#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  pair<long long,int> a[n];
  for(int i = 0;i < n;i++){
    int z;cin >> z;
    a[i] = {z,i};
  }
  sort(a, a + n);
  long long sum = 0;
  int l = 0,r = n - 1;
  for(int i = n - 1;i >= 0;i--){
    cout << a[i].first << " " << a[i].second << endl;
    if(abs(a[i].second - l) > abs(a[i].second - r)){
      sum += a[i].first * abs(a[i].second - l);
      cout << l << " " << abs(a[i].second - l) << " " << sum << endl;
      l++;
    }else{
      
      sum += a[i].first * abs(a[i].second - r);
      
      cout << r << " " << abs(a[i].second - r) << " " << sum << endl;
      r--;
    }
    
  }
  cout << sum;
}