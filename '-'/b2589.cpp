#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define x first
#define y second

const int MAX = 50;

int n, m, ans = INT32_MIN;
char board[MAX][MAX];
int vis[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

pair<int, int> coordi[MAX * MAX];

bool boundary(int x, int y) {
    return (0 <= x && x < n) && (0 <= y && y < m);
}

void bfs(pair<int, int> p) {
    for (int i = 0; i < n; ++i) { // init.
        for (int j = 0; j < m; ++j) {
            vis[i][j] = 0;
        }
    }

    queue<pair<int, int> > q;

    q.push(p);
    vis[p.x][p.y] = 1;

    while (!q.empty()) {
        p = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (!boundary(nx, ny) || vis[nx][ny] || board[nx][ny] == 'W') continue;

            vis[nx][ny] = vis[p.x][p.y] + 1;
            q.push(make_pair(nx, ny));

            // cout << nx << ", " << ny << " : " << vis[nx][ny] << '\n';

            ans = max(ans, vis[nx][ny]);
        }
    }
}

int main(void) {
    cin >> n >> m;

    pair<int, int>* p = coordi;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];

            if (board[i][j] == 'L') {
                *p++ = make_pair(i, j);
            }
        }
    }

    int size = p - coordi;
    for (int i = 0; i < size; ++i) {
        // cout << "start : " << coordi[i].x << ", " << coordi[i].y << '\n' << "-------------" << '\n';
        bfs(coordi[i]);
        // cout << "-------------" << '\n';
    }

    cout << ans - 1 << '\n';
}
