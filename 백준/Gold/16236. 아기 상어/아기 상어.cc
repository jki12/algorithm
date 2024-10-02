#include <bits/stdc++.h>

using namespace std;

#define SIZE 21
#define x first
#define y second

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, ans;
int m = 2;
pair<int, int> pos;
vector<pair<int, int>> v;

int arr[SIZE][SIZE];

int bfs(pair<int, int> s, pair<int, int> d) {
    int vis[SIZE][SIZE] = { 0, };

    queue<pair<int, int>> q;
    q.push(s);

    vis[s.x][s.y] = 1;

    while (q.size()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (0 > nx || nx >= n || 0 > ny || ny >= n || vis[nx][ny] || m < arr[nx][ny]) continue;

            vis[nx][ny] = vis[cur.x][cur.y] + 1;
            q.push({nx, ny});

            if (nx == d.x && ny == d.y) return vis[nx][ny];
        }
    }

    return -1;
}

int find_target() {
    int min_dis = INT_MAX;
    int idx = -1;

    for (int i = 0; i < v.size(); ++i) {
        pair<int, int> cur = v[i];

        if (arr[cur.x][cur.y] >= m) continue;

        int dis = bfs(pos, cur);

        if (dis != -1 && min_dis > dis) {
            idx = i;
            min_dis = dis;
        }
    }

    if (idx != -1) ans += (min_dis - 1);

    return idx;
}

int main(void) {
    cin >> n;
    
    for (int i = 0; i < n * n; ++i) {
        int temp;
        cin >> temp;

        if (temp == 0) continue;
        else if (temp == 9) pos = {i / n, i % n};
        else { v.push_back({i / n, i % n}); arr[i / n][i % n] = temp; }
    }

    int eat_cnt = 0;
    int i;
    while ((i = find_target()) != -1) {
        pos = v[i];

        eat_cnt++;
        if (m == eat_cnt) {
            eat_cnt = 0;
            m++;
        }

        arr[v[i].x][v[i].y] = 0;
        v.erase(v.begin() + i);
    }

    cout << ans << '\n';
}
