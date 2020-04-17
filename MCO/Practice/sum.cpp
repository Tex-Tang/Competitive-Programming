#include <bits/stdc++.h>

using namespace std;

struct fwtree{
    vector<long long> bit;
    long long n;

    fwtree(long long n){
        this->n = n;
        bit.assign(n,0);
    }

    long long sum(long long r) {
        long long result = 0;
        for(;r >= 0;r = (r & (r + 1)) - 1){
            result += bit[r];
        }
        return result;
    }
    
    long long sum(long long l, long long r){
        return sum(r) - sum(l - 1);
    }

    void add(long long idx, long long change) {
        for(;idx < n;idx = (idx | (idx + 1))){
            bit[idx] += change;
        }
    }
};
int main(){
  long long N, Q;
  cin >> N >> Q;
  fwtree bt = fwtree(N),at = fwtree(N);
  long long a[N];
  for(long long i = 0;i < N;i++){
      cin >> a[i];
      at.add(i,a[i]);
      bt.add(i,(i + 1)*a[i]);
  }

  for(long long q = 0;q < Q;q++){
      long long t,p1,p2;
      cin >> t >> p1 >> p2;
      if(t == 1){
          long long l = p1 - 1,r = p2 - 1;
          long long c = l;
          long long result = 0;
          for(long long i = 1;l <= r;i++){
              long long temp_r = l + i - 1;
              if(temp_r > r) temp_r = r;
              if(i % 2 == 1) result += bt.sum(l, temp_r) - c*at.sum(l, temp_r);
              else result += -bt.sum(l, temp_r) + c*at.sum(l, temp_r);
              l += i;
          }
          cout << result << endl;
      }else if(t == 2){
          at.add(p1 - 1,p2 - a[p1 - 1]);
          bt.add(p1 - 1,p1*p2 - p1*a[p1 - 1]);
          a[p1 - 1] = p2;
      }
  }
}