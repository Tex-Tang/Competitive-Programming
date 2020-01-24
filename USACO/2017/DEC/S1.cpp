#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  ifstream fin("homework.in");
  ofstream fout("homework.out");
  int n;
  fin >> n;
  int arr[n];
  for(int i = 0;i < n;i++){
  fin >> arr[i];
  }
  long long sum = 0;
  long double mx = 0.0;
  
  int mix = 10001, mi = -1;
  for(int i = n - 1;i > 0;i--){
    sum += arr[i];
    mix = min(arr[i], mix);
    
    if(i != n - 1){
      long double x = (long double)(sum - mix)/ (n - i - 1);
      if(x > mx){
        mx = x;
        mi = i;
      }
    }
  }
  sum = 0;
  mix = 10001;
  vector <int> a;
  for(int i = n - 1;i > 0;i--){
    sum += arr[i];
    mix = min(arr[i], mix);
    
    if(i != n - 1){
      long double x = (long double)(sum - mix)/ (n - i - 1);
      if(x == mx){
        a.push_back(i);
      }
    }
  }
  for(int i = a.size() - 1;i >= 0;i--) fout << a[i] << endl;
}