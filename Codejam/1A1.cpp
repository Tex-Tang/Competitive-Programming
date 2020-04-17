#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int c = 0;c < T;c++){
    int N;cin >> N;
    string arr[N];
    int max_s_s = 0;
    int max_s_i;
    for(int i = 0;i < N;i++){
      cin >> arr[i];
      if(max_s_s < arr[i].size()){
        max_s_s = arr[i].size();
        max_s_i = i;
      }
    }
    
    string max_s = arr[max_s_i];
    bool yeah = true;
    for(int i = 0;i < N;i++){
      if(i != max_s_i){
        for(int j = 0;j < arr[i].size();j++){
          if(arr[i][j] == '*') break;
          if(max_s[j] != arr[i][j]) yeah = false;
        }
      }
    }
    if(yeah == false){
      cout << "Case #" << c + 1 << ": *" << endl;
    }else{
      cout << "Case #" << c + 1 << ": " + max_s << endl;
    }
  }
}