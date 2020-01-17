#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, A, B;
    cin >> n >> A >> B;
    int arr[n];
    int sum = 0;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr + 1, arr + n);
    if(arr[0]*A/sum >= B){
        cout << 0;return 0;
    }
    for(int i = n - 1;i >= 1;i--){
        sum -= arr[i];
        if(arr[0]*A/sum >= B){
            cout << n - i;
            return 0;
        }
    }

}