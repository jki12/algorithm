#include <bits/stdc++.h>

#define SIZE (101)

using namespace std;

int n, ans = INFINITY;
int board[SIZE][SIZE];
bool vis[SIZE];

void dfs(int k, int idx) {
    if (k == n / 2) {
        int a = 0, b = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (vis[i] && vis[j]) a += board[i][j] + board[j][i];
                if (!vis[i] && !vis[j]) b += board[i][j] + board[j][i];
            }
        }

        ans = min(ans, abs(a - b));

        return;
    }

    for (int i = idx; i < n; ++i) {
        vis[i] = 1;
        dfs(k + 1, i + 1);
        vis[i] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n * n; ++i) {
        cin >> board[i / n][i % n];
    }

    dfs(0, 0);
    
    cout << ans << '\n';
}
