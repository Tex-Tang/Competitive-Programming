#include <bits/stdc++.h>

using namespace std;
int st[100001][18];

long long gcd(long long a, long long b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int query(int l, int r){
  int j = log2(r - l + 1);
  return gcd(st[l][j],st[r - (1 << j) + 1][j]);
}

int binary_search(int l, int r, int start, int val){
  int ans = r;
  while(l <= r){
    int mid = (l + r) / 2;
    if(query(start, mid) == val){
      l = mid + 1;
    }else{
      r = mid - 1;
      ans = min(ans, r);
    }
  }
  return ans;
}


int main(){
  int n;cin >> n;
  int k = log2(n);
  int maxp = 0;
  for(int i = 0;i < n;i++){
    cin >> st[i][0];
    for(int j = 1;j < k + 1;j++) st[i][j] = 0;
    maxp = max(maxp, st[i][0]);
  }

  for(int j = 1;j < k + 1;j++){
    for(int i = 0;i + (1 << j) <= n;i++){
      st[i][j] = gcd(
        st[i][j - 1],
        st[i + (1 << (j - 1))][j - 1]
      );
    }
  }
  map <int, long long> result;
  for(int i = 0;i < n;i++){
    int val = st[i][0];
    int pos = i;
    while(true){
      int p = pos;
      pos = binary_search(p, n - 1, i, val);
      val = query(i, pos);
      result[val] += pos - p + 1;
      if(pos < n - 1){
        pos++;
        val = query(i, pos);
      }else{
        break;
      }
    }
  }
  
  int q;cin >> q;
  for(int i = 0;i < q;i++){
    int z;cin >> z;
    cout << result[z] << endl;
  }
}