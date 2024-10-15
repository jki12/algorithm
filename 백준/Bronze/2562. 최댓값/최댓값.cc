#include <bits/stdc++.h>

using namespace std;

int n, k, idx, mx = INT32_MIN;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    for (int i = 0; i < 9; ++i) {
        cin >> k;

        if (mx < k) {
            mx = k;
            idx = i;
        }
    }

    cout << mx << ' ' << idx + 1;
}