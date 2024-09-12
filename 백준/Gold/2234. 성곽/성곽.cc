#include <bits/stdc++.h>

using namespace std;

#define SIZE (51)

int n, m, x, y, cnt, _max, _max2;
int board[SIZE][SIZE];
int vis[SIZE][SIZE];
int arr[SIZE * SIZE];

int dx[] = { 0, -1, 0, 1 }; // wnes, 비트 마스크 순서.
int dy[] = { -1, 0, 1, 0 };

void recur(pair<int, int> s) {
    if (vis[s.first][s.second]) return;

    cnt++;
    queue<pair<int, int>> q;
    q.push(s);
    vis[s.first][s.second] = cnt;

    int temp = 0;
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        temp++;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 > nx || nx >= n || 0 > ny || ny >= m || board[x][y] & (1 << i)) continue;
            if (vis[nx][ny]) continue;

            q.push({nx, ny});
            vis[nx][ny] = cnt;
        }
    }

    arr[cnt] = temp;
    _max = max(_max, temp);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n * m; ++i) {
        cin >> board[i / m][i % m];
    }

    for (int i = 0; i < n * m; ++i) {
        recur({i / m, i % m});
    }

    for (int i = 0; i < n * m; ++i) {
        for (int j = 0; j < 4; ++j) {
            int nx = i / m + dx[j];
            int ny = i % m + dy[j];

            if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if (vis[i / m][i % m] != vis[nx][ny]) _max2 = max(_max2, arr[vis[i / m][i % m]] + arr[vis[nx][ny]]);
        }
    }

    cout << cnt << ' ' << _max << ' ' << _max2 << '\n';
}
