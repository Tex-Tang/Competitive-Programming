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
  vector <int> d(s.length(),-1);
  int i = 0;
  while(s[i] == ')') i++;
  for(;i < s.length();i++){
    if(s[i] == '('){
      st.push(i);
    }
    if(s[i] == ')' && !st.empty()){
      int j = st.top();
      st.pop();
      d[i] = j;
      d[j] = i;
    }
  }
  int maxx = 0, occur = 0, sum = 0;
  for(int j = 0;j < s.length();j++){
    if(d[j] != -1){
      sum++;
    }else if(d[j] == -1 && sum > 0){
      if(sum == maxx){ occur++; }
      else if (sum > maxx){ 
        maxx = max(maxx, sum);
        occur = 1;
      }
      sum = 0;
    }
  }
  if(sum == maxx){ occur++; }
    else if (sum > maxx){ 
      maxx = max(maxx, sum);
      occur = 1;
    }
  cout << maxx << " " << occur;
}
 