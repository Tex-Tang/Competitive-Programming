#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector < pair<ll,ll> > st;
void build(ll v, ll tl, ll tr){
  if(tl == tr){ st[v] = {0,0}; }
  else{
    ll tm = (tl + tr)/2;
    build(v*2, tl, tm);
    build(v*2 +1, tm + 1, tr);
    st[v] = {0,0}; 
  }
}

void update(ll v,ll tl, ll tr, ll l, ll r,ll ol, ll x, ll y){
  
  if (l > r)
        return;
  else{
    ll tm = (tl + tr)/2;
    if(tl == l && tr == r){ st[v].first += x + (tl - ol)*y; st[v].second += y; }//(tl - l + 1)*y; }
    else{
      update(v*2, tl, tm, l, min(r, tm),ol, x, y);
      update(v*2+1, tm+1, tr, max(l, tm+1), r, ol, x, y);
    }
  }
}

ll get(ll v, ll tl, ll tr, ll pos) {
  /*
  ll sum = 0;
  if (tl == tr){
    for(pair<int, pair<int,int> > p : st[v]){
      sum += p.second.first + p.second.second*(pos - p.first + 1);
    }
    return sum;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm){
    for(pair<int, pair<int,int> > p : st[v]){
      sum += p.second.first + p.second.second*(pos - p.first + 1);
    }
    return sum + get(v*2, tl, tm, pos);
  }
  else {
    for(pair<int, pair<int,int> > p : st[v]){
      sum += p.second.first + p.second.second*(pos - p.first + 1);
    }
    return sum + get(v*2+1, tm+1, tr, pos);
  }*/
  if (tl == tr){
    return st[v].first + (pos - tl + 1)*st[v].second;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm){
    return st[v].first + (pos - tl + 1)*st[v].second + get(v*2, tl, tm, pos);
  }
  else{
    return st[v].first + (pos - tl + 1)*st[v].second + get(v*2+1, tm+1, tr, pos);
  }
    
}

int main(){
  ll n,q;
  cin >> n >> q;
  vector<ll> yt(n,0);
  st.resize(4*n);
  build(1,0,n-1);
  for(ll i = 0;i < q;i++){
    ll l,r,x,y;
    cin >> l >> r >> x >> y;
    update(1,0, n - 1, l, r, l, x, y);
  }
  for(int i = 0;i < n;i++){
    cout << get(1,0,n-1,i) << " ";
  }
}