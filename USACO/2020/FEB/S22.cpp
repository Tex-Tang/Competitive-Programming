#include <bits/stdc++.h>
#include <fstream>
using namespace std;
 
#define MAXN 20005
int main(){
  ifstream fin("triangles.in");
  ofstream fout("triangles.out");
  int N;
  fin >> N;
  pair <int,int> v[N];
  vector<int> same_x[MAXN];
  vector<int> same_y[MAXN];
  for(int i = 0;i < N;i++){
    int x,y;
    fin >> x >> y;
    x += 10000; y += 10000;
    same_x[x].push_back(y);
    same_y[y].push_back(x);
    v[i] = {x , y};
  }
  long long area = 0;
  for(int i = 0;i < N;i++){
    int x = v[i].first;
    int y = v[i].second;
    if(same_y[y].size() > 0 && same_x[x].size() > 0){
      for(auto &ax : same_y[y]){
        if(ax != x){
          for(auto &ay : same_x[x]){
            if(ay != y){
              area += abs((ax - x)*(ay - y));
            }
          }
        }
      }
    }
  }
  fout << ((area) % (1000000007));
}