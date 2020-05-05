#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;cin >> n;
  vector <int> graph[n + 1];
  for(int i = 2;i <= n;i++){
    int p;cin >> p;
    graph[p].push_back(i);
  }
  for(int i = 1;i <= n;i++){
    cout << graph[i].size() << endl;
  }
}