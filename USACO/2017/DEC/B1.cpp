#include <bits/stdc++.h>
#include <fstream>

using namespace std;
int blockedArea(int x1,int y1,int x2,int y2,int x3,int y3, int x4, int y4){
  int left = max(x1,x3);
  int bottom = max(y1,y3);
  int right = min(x2,x4);
  int top = min(y2,y4);
  return (top - bottom)*(right - left);
}

bool overlap(int x1,int y1,int x2,int y2,int x3,int y3, int x4, int y4){
  if(x3 > x2 || x1 > x4) return false;
  if(y1 > y4 || y3 > y2) return false;
  return true;
}

int main(){
  ifstream fin("billboard.in");
  ofstream fout("billboard.out");
  int x5,x6,y5,y6,x1,x2,x3,x4,y1,y2,y3,y4;
  fin >> x1 >> y1 >> x2 >> y2;
  fin >> x3 >> y3 >> x4 >> y4;
  fin >> x5 >> y5 >> x6 >> y6;
  int ans = (x2 - x1)*(y2 - y1) + (x4 - x3)*(y4 - y3);
  if(overlap(x1,y1,x2,y2,x5,y5,x6,y6)){
    ans -= blockedArea(x1,y1,x2,y2,x5,y5,x6,y6);
  }
  if(overlap(x3,y3,x4,y4,x5,y5,x6,y6)){
    ans -= blockedArea(x3,y3,x4,y4,x5,y5,x6,y6);
  }
  fout << ans;
}

