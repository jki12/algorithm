#include <bits/stdc++.h>

#define SIZE (52)

using namespace std;

int r, c, t, ans;
int board[SIZE][SIZE][2];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

pair<int, int> ac = { -1, -1 }; // 공기청정기는 항상 1번 열에 설치되어 있으므로 2개의 r위치를 담고 있는 pair를 만듬.

void left() {
    int x = ac.first - 1;
    int y = 0;

    while (x != 0) {
        board[x][y][0] = board[x - 1][y][0];
        x--;
    }

    while (y < c - 1) {
        board[x][y][0] = board[x][y + 1][0];
        y++;
    }

    while (x != ac.first) {
        board[x][y][0] = board[x + 1][y][0];
        x++;
    }

    while (y != 0) {
        board[x][y][0] = max(board[x][y - 1][0], 0);
        y--;
    }
}

void right() {
    int x = ac.second + 1;
    int y = 0;

    while (x != r - 1) {
        board[x][y][0] = board[x + 1][y][0];
        x++;
    }

    while (y != c - 1) {
        board[x][y][0] = board[x][y + 1][0];
        y++;
    }

    while (x != ac.second) {
        board[x][y][0] = board[x - 1][y][0];
        x--;
    }

    while (y != 0) {
        board[x][y][0] = max(board[x][y - 1][0], 0);
        y--;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> t;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> board[i][j][0];

            if (board[i][j][0] == -1 && ac.first == -1) ac.first = i;
            else if (board[i][j][0] == -1 && ac.first != -1) ac.second = i;
        }
    }
    
    while (t--) {
        for (int i = 0; i < r * c; ++i) {
            int x = i / c;
            int y = i % c;
            
            int temp = 0;
            for (int j = 0; j < 4; ++j) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (0 > nx || nx >= r || 0 > ny || ny >= c || board[nx][ny][0] == -1) continue;

                temp += board[x][y][0] / 5;
                board[nx][ny][1] += board[x][y][0] / 5;
            }

            board[x][y][0] -= temp;
        }

        for (int i = 0; i < r * c; ++i) {
            int x = i / c;
            int y = i % c;
            
            board[x][y][0] += board[x][y][1];
            board[x][y][1] = 0;
        }

        left();
        right();
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            ans += max(board[i][j][0], 0);
        }
    }

    cout << ans << '\n';
}
