#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin >> n;
    int arr[n], mina = 10e9 + 1;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        mina = min(arr[i], mina);
    }
    for(int i = 0;i < n;i++){
        if(arr[i] % mina != 0){
            cout << -1;
            return 0;
        }
    }
    cout << mina;
}