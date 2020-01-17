#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    int mina = 1000000001;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        mina = min(arr[i], mina);
    }
    long long ans = 0;
    for(int i = 0;i < n;i++){
        if((arr[i] - mina) % k == 0 && arr[i] != mina){
            ans += (arr[i] - mina) / k;
        }else if((arr[i] - mina) % k != 0){
            cout << -1; return 0;
        }
    }
    cout << ans;
}