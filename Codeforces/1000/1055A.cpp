#include <bits/stdc++.h>

using namespace std;

int main(){
    int s,n;cin >> s >> n;
    n-=1;
    int arr1[s], arr2[s];
    for(int i = 0;i < s;i++) cin >> arr1[i];
    for(int i = 0;i < s;i++) cin >> arr2[i];
    if(arr1[n] == 1 && arr1[0] == 1){
        cout << "YES";
    }else if(arr1[0] == 0){
        cout << "NO";
    }else if(arr1[n] == 0 && arr2[n] == 0){
        cout << "NO";
    }else if(arr1[n] == 0 && arr2[n] == 1 && arr1[0] == 1){
        int j = n;
        bool success = false;
        for(;j < s;j++){
            if(arr1[j] == 1 && arr2[j] == 1){
                success = true;
                break;
            }
        }
        if(success) cout << "YES";
        else cout << "NO";
    }
}