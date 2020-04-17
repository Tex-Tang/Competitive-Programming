#include <bits/stdc++.h>

using namespace std;

int main(){
    int c; cin >> c;
    for(int z = 0;z < c;z++){
        int n;cin >> n;
        int arr[n][n];
        int sum = 0, row = 0, column = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cin >> arr[i][j];
                if(i == j) sum += arr[i][j];
            }
        }
        bool exist[n + 1];
        for(int i = 0;i < n;i++){
            for(int j = 1;j <= n;j++) exist[j] = false;
            for(int j = 0;j < n;j++){
                if(exist[arr[i][j]]){
                  row++;
                  break;
                }
                exist[arr[i][j]] = true;
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 1;j <= n;j++) exist[j] = false;
            for(int j = 0;j < n;j++){
                if(exist[arr[j][i]]){
                  column++;
                  break;
                }
                exist[arr[j][i]] = true;
            }
        }
        cout << "Case #" << z + 1 << ": " << sum << " " << row << " " << column << endl;
    }
    return 0;
}