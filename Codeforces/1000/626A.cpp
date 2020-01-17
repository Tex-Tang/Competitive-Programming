#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin >> n;
    int ans = 0;
    string str;cin >> str;
    for(int s = 2;s <= n;s++){
        for(int i = 0;i < n - s + 1;i++){
            int u = 0,d = 0,l = 0,r = 0;
            for(int j = i;j < i + s;j++){
                if(str[j] == 'U') u++;
                else if(str[j] == 'D') d++;
                else if(str[j] == 'L') l++;
                else if(str[j] == 'R') r++;
            }
            
            if(u == d && l == r){ans++;}
        }
    }
    cout << ans;
}