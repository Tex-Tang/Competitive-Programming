#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int a,b = 0,c,d = 0; cin >> a;
    for(int i = 0;i < a;i++){
        int z;cin >> z;
        b = max(b, z);
    }
    cin >> c;
    for(int i = 0;i < c;i++){
        int z;cin >> z;
        d = max(d, z);
    }
    cout << b << " " << d ;
    
}