#include <bits/stdc++.h>
#include <fstream>

using namespace std;
 
int main(){
  ifstream fin("swap.in");
  ofstream fout("swap.out");
  int N, M, K;
  fin >> N >> M >> K;
  pair <int,int> pairs[M];
  int cows[N];
  for(int i = 1;i <= N;i++) cows[i] = i;
  for(int i = 0;i < M;i++){
    fin >> pairs[i].first >> pairs[i].second;
  }
  int r = 0;
  for(int i = 0;i < K;i++){
    for(int j = 0;j < M;j++){
      pair <int,int> p = pairs[j];
      reverse(cows + p.first, cows + p.second + 1);
    }
    bool flag = true;
    for(int i = 1;i <= N;i++){
      if(cows[i] != i) flag = false;
    }
    if(flag){
      r = i + 1;
      break;
    }
  }
  if(r != 0){
    K = K % r;
    for(int i = 0;i < K;i++){
      for(int j = 0;j < M;j++){
        pair <int,int> p = pairs[j];
        reverse(cows + p.first, cows + p.second + 1);
      }
    }
  }
  for(int i = 1;i <= N;i++) fout << cows[i] << endl;
}
/*
7 2 10
1 5
3 7*/