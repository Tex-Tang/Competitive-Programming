#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin >> n;
    int mina = 1000000000;
    for(int i = 1;i <= n;i++){
        if(n % i == 0){
            mina = min(mina, 2*i + 2*(n / i));
        }
    }
    cout << mina;
}