#include <bits/stdc++.h>

#define SIZE (100001)

using namespace std;

int n, m, ans;
int arr[SIZE];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> m;

    sort(arr, arr + n);

    int l = 0;
    int r = n - 1;
    while (l < r) {
        int temp = arr[l] + arr[r];

        if (temp == m) ans++;

        if (temp < m) {
            l++;
        } else {
            r--;
        }
    }

    cout << ans << '\n';
}
