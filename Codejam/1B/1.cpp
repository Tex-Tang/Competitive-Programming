#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(ll x,ll y, ll z){
  x = abs(x), y = abs(y);
  return abs(x + y) < z;

}
int main(){
  int n;cin >> n;
  for(int c = 1;c <= n;c++){
    ll x,y;cin >> x >> y;
    cout << "Case #" << c << ": ";
    vector <char> path;
    int lg = log2(abs(abs(x) + abs(y)));
    bool flag = true;
    for(int i = lg;i >= 0;i--){
      ll z = 1 << i;
      /*cout << z << endl;
      cout << x - z << " " << y << endl;
      cout << x + z << " " << y << endl;
      cout << x << " " << y - z << endl;
      cout << x << " " << y + z << endl;*/
      if(check(x - z, y,z)){
        path.push_back('E');
        x -= z;
      }else if(check(x + z, y,z)){
        path.push_back('W');
        x += z;
      }else if(check(x, y - z,z)){
        path.push_back('N');
        y -= z;
      }else if(check(x, y + z,z)){
        path.push_back('S');
        y += z;
      }else{
        flag = false;
        break;
      }
    }
    if(path.empty() || !flag){
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    reverse(path.begin(), path.end());
    for(char v: path)
      cout << v;
    cout << endl;
  }
}