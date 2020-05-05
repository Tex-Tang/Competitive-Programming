#include<bits/stdc++.h>

using namespace std;

vector <int> st;
vector <int> ans;
void build(int v, int tl, int tr){
  if(tl == tr){ st[v] = 0; }
  else{
    int tm = (tl + tr)/2;
    build(v*2, tl,tm);
    build(v*2 + 1, tm + 1, tr);
    st[v] = 0;
  }
}

void update(int v, int tl, int tr, int l, int r, int m){
  int tm = (tl + tr)/2;
  if(tl == tr){
    if(st[v] == 0 && tl != m) st[v] = m + 1;
  }else if(tl >= l && r >= tr && !(tl <= m && m <= tr)){
    if(st[v] == 0 && tl != m) st[v] = m + 1;
    if(st[v] == -1){
      if(st[v*2] < 0) update(v * 2, tl, tm, l, r, m);
      if(st[v*2 + 1] < 0) update(v * 2 + 1, tm + 1, tr, l, r, m);
      if(st[v*2] == 0){ st[v*2] = m + 1; }
      if(st[v*2 + 1] == 0){ st[v*2 + 1] = m + 1;}
    }
  }else{
    if(r <= tm){
      update(v * 2, tl, tm, l, r, m);
    }else if(l > tm){
      update(v * 2 + 1, tm + 1, tr, l, r, m);
    }else{
      update(v * 2, tl, tm, l, r, m);
      update(v * 2 + 1, tm + 1, tr, l, r, m);
    }
    st[v] = (st[v*2] == st[v*2 + 1]) ? st[v*2] : - 1;
  }
}

int get(int v, int tl, int tr, int pos){
  if(tl == tr && tl == pos) return st[v];
  int tm = (tl + tr) / 2;
  if(pos > tm){
    return get(v*2 + 1, tm + 1,tr, pos);
  }else{
    return get(v*2, tl,tm, pos);
  }
}

void dfs(int v, int tl, int tr){
  int tm = (tl + tr) / 2;
  if(tl == tr) cout << st[v] << " ";
  else if(st[v] != -1){
    for(int i = tl;i <= tr;i++) cout << st[v] << " ";
  }else{
    dfs(v*2, tl, tm);
    dfs(v*2 + 1, tm + 1, tr);
  }
}

int main(){
  int n,m;
  cin >> n >> m;
  st.resize(4*n);
  ans.resize(n);
  build(1,0,n-1);
  for(int i = 0;i < m;i++){
    int l,r,m;
    cin >> l >> r >> m;
    update(1,0,n - 1,l - 1,r - 1,m - 1);
  }
  dfs(1,0,n-1);
}