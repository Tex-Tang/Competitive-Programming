#include "fun.h"
#include <iostream>
#include <vector>
using namespace std;
std::vector<int> createFunTour(int N, int Q) {
  int H = hoursRequired(0, N - 1);
  int A = attractionsBehind(0, N - 1);
  bool visited[N];
  vector<int> sequence;
  vector<int> endpoints;
  if(attractionsBehind(N-1,0) == 1){
    endpoints.push_back(0);
  }
  for(int i = 1;i < N;i++){
    if(attractionsBehind(0,i) == 1){
      endpoints.push_back(i);
    }
  }
  int maxx = 0;
  int maxu = 0, maxv = 0;
  for(int i : endpoints){
    for(int j : endpoints){
      if(i != j){
        int res = hoursRequired(i,j);
        if(res >= maxx){
          maxx = res;
          maxu = i, maxv = j;
        }
      }
    }
  }
  visited[maxu] = true, visited[maxv] = true;
  sequence.push_back(maxu);
  sequence.push_back(maxv);
  int n = N - 2;
  int u = maxv;
  //cout << maxu << " " << maxv;
  while(n >= 1){
    int maxxx = 0, maxj;
    for(int j = 0;j < N;j++){
      if(!visited[j] && u != j){
  //      cout << u << " " << j << endl;
        int res = hoursRequired(u,j);
        if(res > maxxx){
          maxxx = res;
          maxj = j;
        }
      }
    }
    n--;
    sequence.push_back(maxj);
    visited[maxj] = true;
    u = maxj;
  }

  return sequence;
}
