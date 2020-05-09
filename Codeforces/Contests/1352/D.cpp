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
  int T;cin >> T;
  for(int t = 0;t < T;t++){
    int n;cin >> n;
    int arr[n];
    int left = 0;
    for(int i = 0;i < n ;i++){
      cin >> arr[i];
      left += arr[i];
    }
    int l = 0, r = n - 1, k = 0;
    int a = 0,b = 0;
    int moves = 0;
    while(r >= l){
      int a1 = arr[l]; l++;
      while(a1 <= k && r >= l){
        a1 += arr[l];
        l++;
      }
      a += a1;
      left -= a1;
      k = a1;
      moves += 1;
      if(r >= l){
        int b1 = arr[r];r--;
        while(b1 <= k && r >= l){
          b1 += arr[r];
          r--;
        }
        b += b1;
        left -= b1;
        k = b1;
        moves += 1;
      }
    }
    cout << moves << " " << a << " " << b << endl;
  }
}