#include <bits/stdc++.h>

using namespace std;

int main(){
  int h1,w1,h2,w2;
  cin >> w1 >> h1 >> w2 >> h2;
  int h = h1 + h2;
  int w = max(w1,w2);
  cout << (w + 2)*2 + h*2;
}