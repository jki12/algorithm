#include <bits/stdc++.h>

using namespace std;

#define SIZE 1000001
#define x first
#define y second

int ans, cur;
int n, m;
pair<int, int> arr[SIZE];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].x >> arr[i].y;

        arr[i].x += 1000000000; // 음수 처리
        arr[i].y += 1000000000;
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; ++i) {
        cur = max(cur, arr[i].x);
        
        if (cur >= arr[i].y) continue;

        ans += arr[i].y - cur;
        cur = arr[i].y;
    }

    cout << ans << '\n';
}