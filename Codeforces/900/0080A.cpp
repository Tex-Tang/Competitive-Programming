#include <bits/stdc++.h>
 
using namespace std;

bool isPrime(int n) 
{ 
  if (n <= 1) 
    return false; 
  if (n <= 3) 
    return true; 

  for (int i = 2; i * i <= n; i++) 
    if (n % i == 0) 
      return false;

  return true; 
} 
int main(){
  int a,b;cin >> a >> b;
  for(int i = a + 1;i < b;i++){
    if(isPrime(i)){
      cout << "NO";
      return 0;
    }
  }
  if(isPrime(b)){
    cout << "YES";
  }else{
    cout << "NO";
  }
}