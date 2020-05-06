#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t = 0;t < T;t++){
    vector <int> ans;
    long long n; cin >> n;
    for(int i = 1;i <= n;i*=2){
      ans.push_back(i);
      n -= i;
    }
    if(n != 0){
      ans.push_back(n);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() - 1 << endl;
    for(int i = 1;i < ans.size();i++){
      cout << ans[i] - ans[i - 1] << " ";
    }
    cout << endl;
  }
}