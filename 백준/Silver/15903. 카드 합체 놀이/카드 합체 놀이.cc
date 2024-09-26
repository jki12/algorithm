#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll ans;
ll n, m, x, y;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> x;

        pq.push(x);
    }

    for (int i = 0; i < m; ++i) {
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();

        pq.push(x + y);
        pq.push(x + y);
    }

    while (pq.size()) {
        ans += pq.top(); pq.pop();
    }

    cout << ans << '\n';
}