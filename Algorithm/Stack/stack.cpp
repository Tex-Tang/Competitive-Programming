#include <bits/stdc++.h>

using namespace std;

int main(){
  // Find minimun in O(1)
  stack< pair<int,int>> st;
  st.push({5 , 5});
  st.push({4 , min(4,st.top().second)});
  st.push({5 , min(5,st.top().second)});
  st.push({3 , min(3,st.top().second)});
  st.push({2 , min(2,st.top().second)});
  cout << st.top().second; // minimum

  deque<int> q;
  q.push_back(5);
  while (!q.empty() && q.back() > 4) q.pop_back();
  q.push_back(4);
  while (!q.empty() && q.back() > 3) q.pop_back();
  q.push_back(3);
  while (!q.empty() && q.back() > 2) q.pop_back();
  q.push_back(2);
  cout << q.front();

  /*
  [5]
  add 4 [4]
  add 4 [4,4]
  add 3 [3]
  */
}