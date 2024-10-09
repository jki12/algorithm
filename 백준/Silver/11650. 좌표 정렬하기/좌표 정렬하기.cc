#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

pair<int, int> arr[100001];
int n;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i].x >> arr[i].y;

    sort(arr, arr + n);

    for (int i = 0; i < n; ++i) cout << arr[i].x << ' ' << arr[i].y << '\n';
}