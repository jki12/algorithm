#include <bits/stdc++.h>

using namespace std;

int n, ans;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int cur = v[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if (cur > v[i]) {
            cur = v[i];
            continue;
        }

        int d = v[i] - cur + 1;

        ans += d;
        cur = v[i] - d;
	}

    cout << ans << '\n';
}
