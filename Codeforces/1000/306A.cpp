#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    if(n % m == 0){
        for(int i = 0;i < m;i++){ cout << n / m << " "; }
    }else{
        for(int i = 0;i < m - (n % m);i++){ cout << n / m << " "; }
        for(int i = 0;i < n % m;i++){ cout << n / m + 1 << " "; }
    }
}

/**
 * %
*/