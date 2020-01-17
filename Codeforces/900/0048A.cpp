#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  string a,b,c;
  cin >> a >> b >> c;
  if((a == b && b == c) || (a != b && b != c && c != a)){
    cout << "?";
  }else{
    if(a == b){
      if(a == "rock" && c == "scissors") cout << "?";
      else if(a == "rock" && c == "paper") cout << "S";
      else if(a == "paper" && c == "rock") cout << "?";
      else if(a == "paper" && c == "scissors") cout << "S";
      else if(a == "scissors" && c == "paper") cout << "?";
      else if(a == "scissors" && c == "rock") cout << "S";
    }else if(b == c){
      if(b == "rock" && a == "scissors") cout << "?";
      else if(b == "rock" && a == "paper") cout << "F";
      else if(b == "paper" && a == "rock") cout << "?";
      else if(b == "paper" && a == "scissors") cout << "F";
      else if(b == "scissors" && a == "paper") cout << "?";
      else if(b == "scissors" && a == "rock") cout << "F";
    }else if(a == c){
      if(a == "rock" && b == "scissors") cout << "?";
      else if(a == "rock" && b == "paper") cout << "M";
      else if(a == "paper" && b == "rock") cout << "?";
      else if(a == "paper" && b == "scissors") cout << "M";
      else if(a == "scissors" && b == "paper") cout << "?";
      else if(a == "scissors" && b == "rock") cout << "M";
    }
  }
}