#include <bits/stdc++.h>

using namespace std;

int n, m;
int cnt[256];
int lis;

int main(void) {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> m;

        int temp = 0;
        for (int j = 0; j < m; ++j) temp = max(temp, cnt[j]);

        cnt[m] = temp + 1;

        lis = max(lis, cnt[m]);
    }

    cout << n - lis << '\n';
}
