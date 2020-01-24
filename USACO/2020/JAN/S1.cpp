#include <bits/stdc++.h>
#include <fstream>

using namespace std;
 
int main(){
  ifstream fin("berries.in");
  ofstream fout("berries.out");
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for(int i = 0;i < N;i++) cin >> a[i];
  sort(a.begin(), a.end());
  while(a[N - 1] / a[N - K/2 - 1] >= 2){
    int d = a[N - 1] / a[N - K/2 - 1];
    int r = a[N - 1] % a[N - K/2 - 1];
    int m = a[N - 1] / d;
    a.pop_back();
    for(int i = 0;i < d;i++){
      a.push_back(m);
    }
    if(r != 0){ a.push_back(r); }
    sort(a.begin(), a.end());
    N = a.size();
  }
  int sum = 0;
  for(int i = N - K/2 - 1;i >= N - K;i--){
    sum += a[i];
  }
  cout << sum;
}