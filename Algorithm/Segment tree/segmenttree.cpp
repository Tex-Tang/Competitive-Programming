#include<bits/stdc++.h>

using namespace std;

vector <int> st;

void build(int a[], int v, int tl, int tr){
  if(tl == tr){ st[v] = a[tl]; }
  else{
    int tm = (tl + tr)/2;
    build(a, v*2, tl, tm);
    build(a, v*2 +1, tm + 1, tr);
    st[v] = st[v*2] + st[v*2 + 1];
  }
}

int sum(int v, int tl, int tr, int l, int r){
  if(l > r){ return 0; }
  if(tl == l && tr == r){
    return st[v];
  }
  int tm = (tl + tr) / 2;
  return sum(v*2, tl, tm, l, min(r,tm)) + sum(v*2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val){
  if(tl == tr){
    st[v] = new_val;
  } else {
    int tm = (tl + tr)/2;
    if(pos <= tm){
      update(v*2, tl, tm, pos, new_val);
    } else {
      update(v*2 + 1, tl, tm, pos, new_val);
    }
    st[v] = st[v*2] + st[v*2 + 1];
  }
}


int main(){
  int a[] = {1,2,3,4,5,6,7,8,9,10};
  st.resize(4 * 10);
  build(a, 1, 0, 9);
  for(;;){
    int l, r;
    cin >> l >> r;
    cout << sum(1, 0, 9, l, r) << endl;
  }
}