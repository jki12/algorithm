#include <bits/stdc++.h>

using namespace std;

#define SIZE 1001

int n, cnt, ans;
int arr[SIZE];
int two[499500 + SIZE];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr, arr + n);

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            two[cnt++] = arr[i] + arr[j];
        }
    }

    sort(two, two + cnt);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int t = arr[i] - arr[j];

            if (binary_search(two, two + cnt, t)) {
                ans = max(arr[i], ans);
            }
        }
    }

    cout << ans << '\n';
}
