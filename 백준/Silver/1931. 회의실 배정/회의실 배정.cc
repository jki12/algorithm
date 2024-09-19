#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int n, a, b, cur, ans;
vector<pair<int, int>> v;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;

        v.push_back({b, a}); // 종료 시간을 기준으로 오름차순으로 정렬하기 위해 반대로 넣어줌.
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i) {
        if (cur > v[i].y) continue;

        cur = v[i].x;
        ans++;
    }

    cout << ans << '\n';
}
