#include <bits/stdc++.h>

using namespace std;

int st[6][100001][18];

int range(int c, int l, int r){
  int j = log2(r - l + 1);
  return max(st[c][l][j], st[c][r - (1 << j) + 1][j]);
}

int main(){
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      cin >> st[j][i][0];
    }
  }

  for(int c = 0;c < m;c++){
    for(int j = 1;j < log2(n) + 1;j++){
      for(int i = 0;i + (1 << j) <= n;i++){
        st[c][i][j] = max(
          st[c][i][j - 1],
          st[c][i + (1 << (j - 1))][j - 1]
        );
      }
    }
  }

  int l = 0;
  int r = n - 1;
  int arr[m];
  fill(arr, arr + m, 0);
  while(r >= l){
    int mid = (l + r)/2;
    bool flag = false;
    for(int i = 0;i < n - mid;i++){
      int sum = 0;
      int tmp[m];
      for(int c = 0;c < m;c++){
        sum += range(c,i,i + mid);
        tmp[c] = range(c,i,i + mid);
      }
      
      if(sum <= k){
        flag = true;
        for(int c = 0;c < m;c++) arr[c] = tmp[c];
      }
    }
    
    if(flag){
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  for(int c = 0;c < m;c++){
    cout << arr[c] << " ";
  }

}