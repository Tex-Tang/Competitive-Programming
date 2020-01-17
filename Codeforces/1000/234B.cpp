#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n,k;
    fin >> n >> k;
    //cin >> n >> k;
    int arr[n],arr2[n];
    for(int i = 0;i < n;i++){ 
        //cin >> arr[i];
        fin >> arr[i]; 
        arr2[i] = arr[i]; 
    }
    sort(arr2, arr2 + n);
    int r = arr2[n - k];
    //cout << r << endl;
    fout << r << endl;
    int s = 0;
    for(int i = 0;i < n && s < k;i++){
        if(arr[i] >= r){
            s++;
            //cout << i + 1 << " ";
            fout << i + 1 << " ";
        }
    }
    
}