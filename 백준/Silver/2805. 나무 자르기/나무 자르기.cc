#include <bits/stdc++.h>

using namespace std;

#define SIZE 1000001
#define ll long long int

ll n, m, l, r, ans;
ll arr[SIZE];

ll check(int x) {
    ll cur = 0;

    for (int i = 0; i < n; ++i) cur += max((ll) 0, arr[i] - x);

    return cur;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i) { cin >> arr[i]; r = max(r, arr[i]); }
    
    int cur = 0;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        ll cnt = check(mid);

        if (cnt >= m) {
            l = mid;

            ans = max(ans, mid);
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}
