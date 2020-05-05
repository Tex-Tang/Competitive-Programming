#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define _               ios_base::sync_with_stdio(0);cin.tie(0)
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define mk(arr,n,type)  type *arr=new type[n];
#define vpii            vector<pair<int,int> >
#define umii            unordered_map<int,int>
#define lli             list<int>
#define gcd(m,n)        __gcd(m,n)
#define mib             map<int,bool>


int main(){
  int n,w;
  cin >> n >> w;
  vpii items(n);
  for(int i = 0;i < n;i++){
    cin >> items[i].first >> items[i].second;
  }
  vector<ll> dp(100001, 1e18L);
  dp[items[0].second] = items[0].first;
  for(int i = 1;i < n;i++){
    ll v = items[i].first, c = items[i].second;
    for(int j = 100000;j >= c;j--){
      dp[j] = min(dp[j], dp[j - c] + v);
    }
    dp[c] = min(dp[c],v);
  }
  for(int j = 100000;j >= 0;j--){
    if(dp[j] <= w){
      cout << j << endl;
      break;
    }
  }
  return 0;
}