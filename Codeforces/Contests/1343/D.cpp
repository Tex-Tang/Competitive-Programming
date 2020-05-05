
#include <bits/stdc++.h>

using namespace std;

vector <int> st;
vector <int> lazy;
int n,k;
void build(int v, int tl, int tr){
  if(tl == tr){ st[v] = n; }
  else{
    int tm = (tl + tr)/2;
    build(v*2, tl, tm);
    build(v*2 +1, tm + 1, tr);
    st[v] = min(st[v*2],st[v*2 + 1]);
  }
}

void push(int v) {
    st[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    st[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        st[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        st[v] = min(st[v*2], st[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -100000000;
    if (l <= tl && tr <= r)
        return st[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main(){
  int T;cin >> T;
  for(int t = 0;t < T;t++){
    cin >> n >> k;
    st.assign(4*(2*k), 0);
    lazy.assign(4*(2*k), 0);
    int a[n];
    build(1, 1, 2*k);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n / 2;i++){
      int a1 = a[i], a2 = a[n - 1 - i];
      int l = min(a1,a2) + 1;
      int r = max(a1,a2) + k;
      update(1, 1, 2*k, l, r, -1);
      update(1, 1, 2*k, a1 + a2, a1 + a2, -1);
    }
    cout << query(1, 1, 2*k,1,2*k) << endl;
  }
}