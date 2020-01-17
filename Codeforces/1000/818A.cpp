#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    long long one = (n / 2) / (k + 1);
    if(one == 0){
        cout << 0 << " " << 0 << " " << n;
    }else{
        cout << one << " " << one*k << " " << n - one*(k + 1);
    }
}