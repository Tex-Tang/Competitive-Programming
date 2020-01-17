#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1,s2,s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    int p1 = 0,p2 = 0, p3 = 0;
    for(int i = 0;i < s1.length();i++){
        if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u'){
            p1++;
        }
    }
    for(int i = 0;i < s2.length();i++){
        if(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u'){
            p2++;
        }
    }
    for(int i = 0;i < s3.length();i++){
        if(s3[i] == 'a' || s3[i] == 'e' || s3[i] == 'i' || s3[i] == 'o' || s3[i] == 'u'){
            p3++;
        }
    }

    if(p1 == 5 && p2 == 7 && p3 == 5){
        cout << "YES";
    }else{
        cout << "NO";
    }
}