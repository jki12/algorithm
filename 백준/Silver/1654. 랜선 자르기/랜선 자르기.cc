#include <bits/stdc++.h>

using namespace std;

#define SIZE 10001

uint n, m, l, ans, r = INT32_MAX;
uint arr[SIZE];

int check(int x) {
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        cnt += (arr[i] / x);
    }

    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    int cur = 0;
    while (l <= r) {
        uint mid = (l + r) / 2;
        uint cnt = check(mid);

        if (cnt >= m) { // lower_bound.
            l = mid + 1;

            ans = max(ans, mid);
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}
