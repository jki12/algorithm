#include <bits/stdc++.h>

using namespace std;

#define SIZE 10000
#define x first
#define y second

int n, p, d, ans;
pair<int, int> arr[SIZE];
int sc[SIZE];

int comp(pair<int, int> a, pair<int, int> b) {
    return a.x > b.x;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> p >> d;

        arr[i] = { p, d };
    }

    sort(arr, arr + n, comp);
    for (int i = 0; i < n; ++i) {
        for (int j = arr[i].y; j > 0; --j) {
            if (!sc[j]) {
                sc[j] = 1;

                ans += arr[i].x;
                break;
            }
        }
    }

    cout << ans << '\n';
}
