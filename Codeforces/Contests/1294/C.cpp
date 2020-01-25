#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int x = 0;x < t;x++){
    int n;
    cin >> n;
    vector <int> arr;
    int i = 2;
    for(;i * i <= n;i++){
      if(n % i == 0){
        arr.push_back(i);
        n /= i;
        i += 1;
        break;
      }
    }
    for(;i * i <= n;i++){
      if(n % i == 0){
        arr.push_back(i);
        n /= i;
        break;
      }
    }
    if(arr.size() >= 2 && n != 1 && n != arr[0] && n != arr[1]){
      cout << "YES" << endl;
      cout << arr[0] << " "<< arr[1] << " " << n << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}