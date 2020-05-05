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
  //ios_base::sync_with_stdio(0);
	//cin.tie(0);
  string s; cin >> s;
  stack <int> st;
  int dp[s.length() + 1];
  dp[0] = 0;
  for(int i = 0;i < s.length();i++){
    dp[i + 1] = 0;
    if(s[i] == '('){
      st.push(i);
    }
    if(s[i] == ')' && !st.empty()){
      int j = st.top();
      dp[i + 1] = dp[j] + i - j + 1;
      st.pop();
    }
  }
  int maxx = 0, occur = 1;
  for(int i = 1;i <= s.length();i++){
    
    if(dp[i] == maxx && maxx > 0){ occur++;}
    else if (dp[i] > maxx){ 
      maxx = max(dp[i],maxx);
      occur = 1; 
    }
  }
  cout << maxx << " " << occur;
}