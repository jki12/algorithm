#include <bits/stdc++.h>

using namespace std;

int t, p, q, r, s, w;

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> p >> q >> r >> s >> w;

        int a = p * w;
        int b = q + max(0, w - r) * s;

        cout << min(a, b) << '\n';
    }

    return 0;
}