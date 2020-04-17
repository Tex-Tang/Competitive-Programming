#include <bits/stdc++.h>

using namespace std;

void complement(int* arr, int s, int n){
  for(int i = s;i < n;i++){
    if(arr[i] != - 1){
      arr[i] = !arr[i];
    }
  }
}

int main(){
  int T, B;cin >> T >> B;
  for(int t = 0;t < T;t++){
    int arr[B + 1];
    for(int i = 1;i <= B;i++) arr[i] = -1;
    int l = 1,r = B;
    int query = 1;
    for(;query <= 10;query++){
      if(query % 2 == 1){ cout  << l << endl; int c;cin >> c; arr[l] = c; l++; } 
      if(query % 2 == 0){ cout  << r << endl; int c;cin >> c; arr[r] = c; r--; }
    }
    while(query <= 150){
      vector<pair<int,int>> unpaired;
      vector<pair<int,int>> paired;
      // find unpaired and paired
      for(int i = 1,j = B;i < l && j > r;i++,j--){
        if(arr[i] != -1 && arr[j] != -1 && arr[i] != arr[j]){
          unpaired.push_back(make_pair(i,j));
        }
        if(arr[i] != -1 && arr[j] != -1 && arr[i] == arr[j]){
          paired.push_back(make_pair(i,j));
        }
      }
      if(unpaired.size() > 0 && paired.size() > 0){
        int ori[] = {
          arr[paired[0].first],
          arr[unpaired[0].first],
          arr[unpaired[0].second],
          arr[paired[0].second]
        };
        int c, comp[3];
        cout  << paired[0].first << endl;    cin >> c; comp[0] = c; query++;
        cout  << unpaired[0].first << endl;  cin >> c; comp[1] = c; query++;
        cout  << unpaired[0].second << endl; cin >> c; comp[2] = c; query++;
        if(ori[1] != comp[1] && ori[2] != comp[2]){
          if(ori[0] == comp[0]){
            // rev
            reverse(arr + 1, arr + B + 1);
            if(l > B - r + 1){
              l--;
              r--;
            }else if(l < B - r + 1){
              l++;
              r++;
            }
          }else{
            // com
            complement(arr, 1, B + 1);
          }
        }else{
          if(ori[0] != comp[0]){
            //rev + com
            reverse(arr + 1, arr + B + 1);
            complement(arr, 1, B + 1);
            if(l > B - r + 1){
              l--;
              r--;
            }else if(l < B - r + 1){
              l++;
              r++;
            }
          }
        }
      }else if(unpaired.size() > 0){
        int ori[] = {
          arr[unpaired[0].first],
          arr[unpaired[1].first],
          arr[unpaired[1].second],
          arr[unpaired[0].second]
        };
        int c, comp[3];
        cout  << unpaired[1].first << endl;  cin >> c; comp[1] = c; query++;
        cout  << unpaired[1].second << endl; cin >> c; comp[2] = c; query++;
        if(ori[1] != comp[1] && ori[2] != comp[2]){
          // rev or com same thing
          reverse(arr + 1, arr + B + 1);
          if(l > B - r + 1){
              l--;
              r--;
            }else if(l < B - r + 1){
              l++;
              r++;
            }
        }
      }else if(paired.size() > 0){
        int ori[] = {
          arr[paired[0].first],
          arr[paired[1].first],
          arr[paired[1].second],
          arr[paired[0].second]
        };
        int c, comp[3];
        cout  << paired[1].first << endl;  cin >> c; comp[1] = c; query++;
        cout  << paired[1].second << endl; cin >> c; comp[2] = c; query++;
        if(ori[1] != comp[1] && ori[2] != comp[2]){
          // com or rev + com same thing
          complement(arr, 1, B + 1);
        }
      }
      int n = (int(query / 10) + 1) * 10;
      for(;query <= n;query++){
        if(l > r){ cout  << 1 << endl;int c;cin >> c; continue; }
        int q = query;
        if(l <= B - r + 1){ cout  << l << endl; int c;cin >> c; arr[l] = c; l++; } 
        else if(l > B - r + 1){ cout  << r << endl; int c;cin >> c; arr[r] = c; r--; }
      }
    }
    
    for(int i = 1;i <= B;i++){
      cout << arr[i];
    }
    cout << endl;
    char ans;cin >> ans;
    if(ans == 'Y'){ continue; }
    else{ break; }
  }
}
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
//1 0 1 0 1 0 1 0 1 0  1  0  1  0  1  0  1  0  1  0  
//0 1 0 1 0 1 0 1 0 1  0  1  0  1  0  1  0  1  0  1