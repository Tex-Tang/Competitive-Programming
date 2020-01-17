#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int rock = 0;
    int maxrock = 0;
    for(int i = 0;i < s.length();i++){
        if(s[i] == '#'){
            rock++;
            maxrock = max(maxrock, rock);
        }else{
            rock = 0;
        }
    }
    if(maxrock < k){
        cout << "YES";
    }else{
        cout << "NO";
    }
}