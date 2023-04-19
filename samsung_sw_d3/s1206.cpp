#include <bits/stdc++.h>

using namespace std;

const int case_count = 10;

int n;
int arr[1001];

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i = 1; i <= case_count; ++i) {
        cin >> n;

        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }

        int ans = 0;
        if (n == 4) {
            cout << ans << '\n';
        }
        else {
            for (int j = 2; j < n - 2; ++j) {
                ans += max(0, arr[j] - max(max(arr[j - 1], arr[j - 2]), max(arr[j + 1], arr[j + 2])));
            }
        }

        cout << '#' << i << ' ' << ans << '\n';
    }

    return 0;
}