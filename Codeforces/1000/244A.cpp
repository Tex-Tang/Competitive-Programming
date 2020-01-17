#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;cin >> n >> k;
    int index[n * k + 1];
    for(int i = 1;i <= n*k;i++) index[i] = -1;
    for(int i = 1;i <= k;i++){
        int a;cin >> a;
        index[a] = i;
    }
    int j = 1;
    int c = 1;
    for(int i = 1;i <= n*k;i++){
        if(index[i] == -1){
            index[i] = j;
            c++;
        }
        if(c == n){
            j++;
            c = 1;
        }
    }
    for(int i = 1;i <= k;i++){
        for(int z = 1;z <= n*k;z++){
            if(index[z] == i){
                cout << z << " ";
            }
        }
        cout << endl;
    }
}