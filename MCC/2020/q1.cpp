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
  string S = "hnizmkiemzrj";
int K = 4;
string A = "jhxruswpkqcebzgdfaoliyntvm";
string B = "grzxjfiphevbwomcytkdaqlnsu";




  char T[26];
  for(int i = 0;i < A.length();i++){
    T[int(A[i]) - 97] = B[i];
  }
  string Z = S;
  for(int i = 0;i < K;i++){
    for(int j = 0;j < S.length();j++){
      S[j] = T[int(S[j]) - 97];
      if(Z == S){
        K = K % (i + 1);
        break;
      }
    }
  }
  cout << K;
  for(int i = 0;i < K;i++){
    for(int j = 0;j < S.length();j++){
      Z[j] = T[int(Z[j]) - 97];
    }
  }

  cout << Z;
  
}