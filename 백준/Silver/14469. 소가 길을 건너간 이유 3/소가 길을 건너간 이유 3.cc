#include <bits/stdc++.h>

using namespace std;

int n, a, b, cur; // 도착 시각과 검문 시간
vector<pair<int, int>> v;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;

        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i) {
        cur = max(cur, v[i].first);

        cur += v[i].second;
    }

    cout << cur << '\n';
}
