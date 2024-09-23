#include <bits/stdc++.h>

#define SIZE (104)

using namespace std;

int n, k, cur, dir, x, y;
int board[SIZE][SIZE];
deque<pair<int, int>> sn;
queue<pair<int, char>> q;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        cin >> x >> y;

        board[x - 1][y - 1] = 1; // board에서 사과는 1, 뱀이 있는 위치는 2, 아무것도 없으면 0
    }

    char c;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x >> c;

        q.push({x, c});
    }

    sn.push_front({0, 0});

    while (1) {
        if (q.size() && q.front().first == cur) {
            if (q.front().second == 'D') dir = (dir + 1) % 4;
            else dir = (dir - 1 < 0) ? 3 : dir - 1;

            q.pop();
        }

        pair<int, int> head = sn.front();
        pair<int, int> tail = sn.back();

        int nx = head.first + dx[dir];
        int ny = head.second + dy[dir];

        if (0 > nx || nx >= n || 0 > ny || ny >= n || board[nx][ny] == 2) break;


        if (board[nx][ny] == 0) {
            board[tail.first][tail.second] = 0;
            sn.pop_back();
        }
        
        sn.push_front({nx, ny});
        board[nx][ny] = 2;

        cur++;
    }

    cout << cur + 1 << '\n';
}
