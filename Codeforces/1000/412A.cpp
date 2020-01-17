#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    string s;
    cin >> n >> k;
    cin >> s;
    
    if(k == 1){
        for(int i = 0;i < n;i++){
            cout << "PRINT " << s[i] << endl;
            if(i != n - 1){
                cout << "RIGHT" << endl;
            }
        }
    }else if(k == n){
        for(int i = n - 1;i >= 0;i--){
            cout << "PRINT " << s[i] << endl;
            if(i != 0){
                cout << "LEFT" << endl;
            }
        }
    } else {
        bool right = (n - k) < k;
        if((n - k) < k){
            for(int i = k;i < n;i++){ cout << "RIGHT" << endl; }
        }else{
            for(int i = k;i > 1;i--){ cout << "LEFT" << endl; }
        }

        if(right){
            for(int i = n - 1;i >= 0;i--){
                cout << "PRINT " << s[i] << endl;
                if(i != 0){
                    cout << "LEFT" << endl;
                }
            }
        }else{
            for(int i = 0;i < n;i++){
                cout << "PRINT " << s[i] << endl;
                if(i != n - 1){
                    cout << "RIGHT" << endl;
                }
            }
        }
    }
    
}