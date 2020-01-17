#include <bits/stdc++.h>

using namespace std;

int main(){
  int q;cin >> q;
  for(int i = 0;i < q;i++){
    long long n;
    int a,b;
    cin >> n >> a >> b;
    if(double(a) > double(b) / 2){
      cout << (n / 2)*b + (n % 2)*a << endl;
    }else{
      cout << n * a << endl;
    }
  }
}