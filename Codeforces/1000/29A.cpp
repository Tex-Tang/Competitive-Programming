#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin >> n;
    pair<int,int> arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i].first;
        cin >> arr[i].second;
    }
    for(int i = 0;i < n;i++){
        int x = arr[i].first;
        int d = arr[i].second;
        for(int j = 0;j < n;j++){
            int x1 = arr[j].first;
            int d1 = arr[j].second;
            if(i != j){
                if(x + d == x1 && x1 + d1 == x){
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}