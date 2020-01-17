#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	int arr[n];
	int ans[n];
	ans[0] = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		ans[i] = 0;
	}
	for(int i = 0;i < n - 1;i++){
		int p = 0;
		while((i + (1 << p)) < n){ p++; }
		int r = i + (1 << (p - 1));
		arr[r] += arr[i];
		ans[i + 1] = ans[i] + arr[i];
		arr[i] = 0;
	}

	for(int i = 1;i < n;i++){
		cout << ans[i] << endl;
	}
}
/**
 * ios_base::sync_with_stdio(false);
 * cin.tie(NULL);
 * 1 << n == 2^n
*/