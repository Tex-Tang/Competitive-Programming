#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int dot = 0;
    for(int i = 0;i < s.length();i++){
        if(s[i] == '.'){
            dot = i;
            break;
        }
    }
    if(s[dot - 1] != '9'){
        int x = s[dot + 1] - '0';
        if(x > 4){
            int x = s[dot - 1] - '0' + 1;
            s[dot - 1] = (char)(48 + x);
        }
        cout << s.substr(0, dot);
    }else{
        cout << "GOTO Vasilisa.";
    }
}