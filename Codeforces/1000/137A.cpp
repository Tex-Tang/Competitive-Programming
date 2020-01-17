#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int t = 0;
    char ts = s[0];
    int ans = 0;
    for(int i = 0;i < s.length();i++){
        ans++;
        int j = i;
        while(s[j] == s[j+1] && j - i + 1 < 5){ j++; }
        i = j;
    }
    cout << ans;
}