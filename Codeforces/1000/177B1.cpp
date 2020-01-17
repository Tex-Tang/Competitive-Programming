#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int ans = n;
    while(n > 1){
        bool s = false;
        for(int i = 2;i <= sqrt(n);i++){
            if(n % i == 0){
                ans += n / i;
                n = n / i;
                s = true;
                break;
            }
        }
        if(!s){
            ans += 1;
            n = 1;
        }
    }
    cout << ans;
}
/**
 * Finding divisor
 */