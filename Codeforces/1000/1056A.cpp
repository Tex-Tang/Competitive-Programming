#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int stop[101];
    for(int i = 0;i < 101;i++) stop[i] = 0;
    for(int i = 0;i < n;i++){
        int r;cin >> r;
        for(int j = 0;j < r;j++){
            int z;cin >> z;
            stop[z]++;
        }
    }
    for(int i = 0;i < 101;i++){
        if(stop[i] == n){
            cout << i << " ";
        }
    }
}