#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin >> n;
    vector<pair<int,int>> arr;
    for(int i = 0;i < n;i++){
        int a,x;
        cin >> a >> x;
        arr.push_back(make_pair(a,x));
    }
    int m;cin >> m;
    for(int i = 0;i < m;i++){
        int a,x;
        cin >> a >> x;
        arr.push_back(make_pair(a,x));
    }
    sort(arr.begin(), arr.end());
    arr.push_back(make_pair(0,0));
    long long ans = 0;
    for(int i = 0;i < n + m;i++){
        if(arr[i].first == arr[i + 1].first){
            ans += max(arr[i].second, arr[i + 1].second);
            i++;
        
        }else{
            ans += arr[i].second;
        }
    }
    cout << ans;
}