#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n; cin >> n;
    long long sum = n * (n + 1) / 2;
    for(int i = 0;i < n - 1;i++){
        long long z;cin >> z; sum -= z;
    }
    cout << sum;
}