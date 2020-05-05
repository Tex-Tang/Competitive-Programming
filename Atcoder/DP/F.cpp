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
  string s,t;
  cin >> s;
  cin >> t;
  int dp[s.length() + 1][t.length() + 1];

  for(int i = 0;i <= s.length();i++){ dp[i][0] = 0; }
  for(int i = 0;i <= t.length();i++){ dp[0][i] = 0; }

  for(int i = 1;i <= s.length();i++){
    for(int j = 1;j <= t.length();j++){
      if(s[i - 1] == t[j - 1]){
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }else{
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  string result;
  result.resize(dp[s.length()][t.length()]);
  int z = dp[s.length()][t.length()] - 1;
  int i = s.length();
  int j = t.length();
  while(i >= 0 && j >= 0){
    if(dp[i][j] == dp[i][j - 1]){
      j--;
    }else if(dp[i][j] == dp[i - 1][j]){
      i--;
    }else{
      result[z] = s[i - 1];
      i--,j--,z--;
    }
  }
  cout << result << endl;
}

/*
  a b y x b
a 1 1 1 1 1
x 1 1 1 2 2
y 1 1 2 2 2
b 1 2 2 2 3
*/