#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  for(int p = 0;p < n;p++){
    string s;
    cin >> s;
    int depth = 0;
    int i = 0;
    while(i < s.length()){
      int z = s[i] - '0';
      while(z > depth){
        s.insert(i,1,'(');
        i++;
        depth++;
      }
      while(z < depth){
        s.insert(i,1,')');
        i++;
        depth--;
      }
      i++;
    }
    s.insert(s.length(),depth,')');
    cout << "Case #" << p + 1 << ": " << s << endl;
  }
}