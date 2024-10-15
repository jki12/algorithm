#include <bits/stdc++.h>

using namespace std;

int n, k, mx = INT32_MIN, mn = INT32_MAX;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;

        mx = max(mx, k);
        mn = min(mn, k);
    }

    cout << mn << ' ' << mx;
}