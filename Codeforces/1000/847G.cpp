#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin >> n;
    string strs[n];
    for(int i = 0;i < n;i++){
        cin >> strs[i];
    }
    int ans = 0;
    for(int i = 0;i < strs[0].length();i++){
        int s = 0;
        for(int j = 0;j < n;j++){
            if(strs[j][i] == '1'){
                s++;
            }
        }
        ans = max(ans, s);
    }
    cout << ans;
}