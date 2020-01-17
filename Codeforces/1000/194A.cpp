#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int r = k - n * 2;
    if(r == 0){
        cout << n;
    }else{
        if(r / n > 0){
            cout << 0;
        }else{
            cout << n - r;
        }
    }
}