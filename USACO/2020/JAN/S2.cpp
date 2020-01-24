#include <bits/stdc++.h>
#include <fstream>

using namespace std;
long long N, K, M;
bool check(long long x){
  long long g = 0;
  long long k = 0;
  if(K > 100000){
    for(int i = N/x;i > M;i--){
      if((N - g) - i*x < 0){
        continue;
      }
      long long d = ((N - g) - i*x)/i + 1;
      g += d*i;
      k += d;
    }
    g += (K - k)*M;
  }else{
    k = 1;
    for(;k <= K;k++){
      long long y = (N - g)/x;
      if(y < M){
        break;
      }else{
        g += y;
      }
      if(g + (K - k)*M >= N){
        return true;
      }
    }
    g += (K - k + 1)*M;
  }

  
  return g >= N;
}
int main(){
  ifstream fin("loan.in");
  ofstream fout("loan.out");
  fin >> N >> K >> M;
  long long l = 1;
  long long r = K;
  while(r >= l){
    long long mid = (r + l)/2;
    if(check(mid)){
      l = mid+1;
    }else{
      r = mid-1;
    }
  }
  fout << r;
}