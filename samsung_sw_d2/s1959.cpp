#include <bits/stdc++.h>

using namespace std;

const int len = 21;

int t, n, m;

int a[len];
int b[len];

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int temp;

    cin >> t;
    for (int case_number = 1; case_number <= t; ++case_number) {
        int ans = INT32_MIN;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];

        for (int i = 0; i <= max(n, m) - min(n, m); ++i) {
            temp = 0;

            for (int j = 0; j < min(n, m); ++j) {
                temp += ((n < m) ? a[j] * b[i + j] : b[j] * a[i + j]);
            }

            ans = max(ans, temp);
        }

        cout << '#' << case_number << ' ' << ans << '\n';
    }

    return 0;
}