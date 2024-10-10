#include <bits/stdc++.h>

using namespace std;

#define SIZE 1000001

int n, k, l, ans, r = 1000000000;
int arr[SIZE];

int check(int x) {
    int cnt = 0;

    for (int i = 0; i < k; ++i) {
        cnt += (arr[i] / x);
    }

    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < k; ++i) cin >> arr[i];
    
    int cur = 0;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        int cnt = check(mid);

        if (cnt >= n) {
            l = mid;

            ans = max(ans, mid);
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}
