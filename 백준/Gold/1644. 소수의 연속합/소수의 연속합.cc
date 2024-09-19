#include <bits/stdc++.h>

using namespace std;

int n, cur, ans;
queue<int> q;

bool arr[4000001];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    fill(arr + 2, arr + n + 1, 1);

    for (int i = 2; i <= n; ++i) {
        if (!arr[i]) continue;

        for (int j = 2; i * j <= n; ++j) arr[i * j] = 0;
    }

    int cur = 0;
    for (int i = n; i >= 0; --i) {
        if (!arr[i] || i > n) continue;

        cur += i;
        q.push(i);

        if (cur == n) ans++;
        if (cur > n) {
            cur -= q.front(); q.pop();
        }
    }

    cout << ans << '\n';
}
