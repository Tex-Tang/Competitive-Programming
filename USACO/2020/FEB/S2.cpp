#include <bits/stdc++.h>
#include <fstream>


using namespace std;
 
#define MAXN 20005
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

int main(){
  int N;
  cin >> N;
  pair <int,int> v[N];
  vector <int> same_x[MAXN];
  vector <int> same_y[MAXN];
  for(int i = 0;i < N;i++){
    int x,y;
    cin >> x >> y;
    x += 10000; y += 10000;
    same_x[x].push_back(y);
    same_y[y].push_back(x);
    v[i] = {x , y};
  }
  double area = 0;
  /*for(int i = 0;i < N;i++){
    int x = v[i].first;
    int y = v[i].second;
    cout << x << " " << y << endl;*/
    for(int i = 0;i < MAXN;i++){
      for(auto &ax : same_y[i]){
        for(auto &ay : same_x[ax]){
          cout << ax << " " << i << endl;
          area += abs(double(ax - x)*double(ay - y))/2;
        }
      }
    }
    //}
    
    //cout << endl;
  //}
  cout << area;
}