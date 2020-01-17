#include <bits/stdc++.h>

using namespace std;

int main(){
    int d, n;cin >> d >> n;
    int sum = 0;
    int z;
    for(int i = 0;i < n - 1;i++){
        cin >> z;
        sum += d - z;
    }
    cin >> z;
    cout << sum;
}