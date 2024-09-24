#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

int n, l, ans;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> l;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
    }

    sort(v.begin(), v.end());

    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int dis = v[i].y - v[i].x;

        cur = max(cur, v[i].x);

        while (cur < v[i].y) {
            cur += l;
            ans++;
        }
    }

    cout << ans << '\n';
}
