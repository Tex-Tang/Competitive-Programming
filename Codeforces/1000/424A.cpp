#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int big = 0, small = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == 'X') big++;
        else small++;
    }
    int d = abs(big - small) / 2;
    cout << d << endl;
    bool cbig = big < small;
    for(int i = 0;i < n;i++){
        if(d == 0){
            break;
        }
        if(cbig && s[i] == 'x'){
            s[i] = 'X';
            d--;
        }else if(!cbig && s[i] == 'X'){
            s[i] = 'x';
            d--;
        }
        
    }
    cout << s;
}