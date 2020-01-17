#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    string s;
    fin >> s;
    int a; fin >> a;
    if(s == "front"){
        if(a == 1){
            fout << "L";
        }else{
            fout << "R";
        }
    }else{
        if(a == 1){
            fout << "R";
        }else{
            fout << "L";
        }
    }
}