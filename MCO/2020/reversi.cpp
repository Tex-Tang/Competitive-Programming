#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> parent;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b){
      parent[b] = a;
    }
}

int main(){
  int n;cin >> n;
  vector < vector< pair<ll,ll> >> result;
  vector < pair<ll,ll> > a;
  parent.resize(n);
  for(int i = 0;i < n;i++){
    pair<ll,ll> p;
    cin >> p.first >> p.second;
    a.push_back(p);
    parent[i] = i;
  }
  int re = n;
  for(int i = 0;i < n;i++){
    bool flag = false;
    for(int j = 0;j < i;j++){
      if(i != j){
        pair<ll,ll> p = a[j];
        if(abs(a[i].first - p.first) == abs(a[i].second - p.second)){
          if(find_set(i) != find_set(j)) re--;
          flag = true;
          union_sets(i,j);
        }
      }
    }
  }
  cout << re;
}