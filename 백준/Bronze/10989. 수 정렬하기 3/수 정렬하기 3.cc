#include <bits/stdc++.h>

using namespace std;

int arr[10001];
int n, m, mx;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> m;

        arr[m]++;
        mx = max(mx, m);
    }

    for (int i = 1; i <= mx; ++i) {
	    for (int j = 0; j < arr[i]; ++j) cout << i << '\n';
	}
}