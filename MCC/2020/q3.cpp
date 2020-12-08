#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<x<<endl;
#define v(T) vector<T>
#define vv(T) v(v(T))
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;


int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  long long N;
  cin >> N;
  long long t = N / 104;
  N %= 104;
  N -= 5;
  long long res = 1;
  list<int> l = {2,0,2,2,1};
  int sum = 7;
  int sum2 = 7;
  for(long long  i = 0;i < N;i++){
    sum = sum2;
    sum %= 3;
    if(sum == 0){
      res++;
    }
    sum2 += sum;
    sum2 -= l.front(); 
    
    l.pop_front();
    l.push_back(sum);
  }
  cout << res + 35 * t;
}