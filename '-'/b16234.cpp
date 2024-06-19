#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define x first
#define y second

const int MAX = 50;

int n, l, r, ans;
int board[MAX][MAX];
bool vis[MAX][MAX];
bool has_move;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool boundary(int x, int y) {
    return (0 <= x && x < n) && (0 <= y && y < n);
}

void bfs(pair<int, int> p) {
    queue<pair<int, int> > q;
    queue<pair<int, int> > temp;

    if (!vis[p.x][p.y]) {
        q.push(p);

        vis[p.x][p.y] = true;
        temp.push(make_pair(p.x, p.y));
    }

    int count = 1; // 열린 국경 수
    int popu = board[p.x][p.y];

    while (!q.empty()) {
        p = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (!boundary(nx, ny) || vis[nx][ny] || l > abs(board[p.x][p.y] - board[nx][ny]) || r < abs(board[p.x][p.y] - board[nx][ny])) continue;

            vis[nx][ny] = true;
            temp.push(make_pair(nx, ny));

            popu += board[nx][ny];
            count++;

            q.push(make_pair(nx, ny));
        }
    }

    // 다른 지역에서 이동이 있었던 경우가 있을 수 있기 때문에 or로 판단
    has_move = has_move || (temp.size() > 1);

    int avg = popu / count;
    while (!temp.empty()) {
        p = temp.front(); temp.pop();

        board[p.x][p.y] = avg;
    }
}

int main(void) {
    vector<int> v{1, 2, 3};

    // cout << "ho" << '\n';
}
