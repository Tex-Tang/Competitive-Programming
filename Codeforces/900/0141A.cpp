#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  string a,b,c;
  cin >> a >> b >> c;
  int count[26];
  for(int i = 0;i < 26;i++) count[i] = 0;
  for(int i = 0;i < a.length();i++) count[a[i] - 'A']++;
  for(int i = 0;i < b.length();i++) count[b[i] - 'A']++;
  for(int i = 0;i < c.length();i++) count[c[i] - 'A']--;
  for(int i = 0;i < 26;i++){
    if(count[i] != 0){ cout << "NO"; return 0; }
  }
  cout << "YES";
}