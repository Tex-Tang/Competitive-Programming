#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
vector <int> st;
vector <int> a;
void build(int v, int tl, int tr){
  if(tl == tr){ st[v] = a[tl]; }
  else{
    int tm = (tl + tr)/2;
    build(v*2, tl, tm);
    build(v*2 + 1, tm + 1, tr);
    if(int(log2(double(tr - tl + 1))) % 2 == 1){
      st[v] = st[v*2] | st[v*2 + 1];
    }else{
      st[v] = st[v*2] ^ st[v*2 + 1];
    }
  }
}

void update(int v, int tl, int tr, int pos, int new_val){
  if(tl == tr){ st[v] = new_val; }
  else{
    int tm = (tl + tr)/2;
    
    if(tm >= pos){
      update(v*2, tl, tm, pos, new_val);
    }else{
      update(v*2 + 1, tm + 1, tr, pos, new_val);
    }
    if(int(log2(double(tr - tl + 1))) % 2 == 1){
      st[v] = st[v*2] | st[v*2 + 1];
    }else{
      st[v] = st[v*2] ^ st[v*2 + 1];
    }
  }
}

int main(){
  int n,m;
  cin >> n >> m;
  st.resize((1 << (n + 1)));
  a.resize((1 << n));
  for(int i = 0;i < (1 << n);i++) cin >> a[i];
  build(1,0,(1 << n) - 1);
  for(int i = 0;i < m;i++){
    int p,b;
    cin >> p >> b;
    update(1,0,(1 << n) - 1,p - 1,b);
    cout << st[1] << endl;
  }
}