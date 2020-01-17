#include <bits/stdc++.h>

using namespace std;

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    r = r / 2 + r % 2;
    g = g / 2 + g % 2;
    b = b / 2 + b % 2;
    cout << max(30 + (r - 1) * 3, max(31 + (g - 1) * 3, 32 + (b - 1) * 3));
}