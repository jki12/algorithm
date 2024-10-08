#include <bits/stdc++.h>

using namespace std;

#define SIZE 32

int r, c;
int ans = 1;

char board[SIZE][SIZE];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int get_count(int mask) {
    int count = 0;

    while (mask) {
        if (mask & 1) count++;
        mask >>= 1;
    }

    return count;
}

void recur(int x, int y, int mask, int cnt) {
    int flag = 1 << (board[x][y] - 65);
    // ans = max(ans, cnt);

    mask |= flag;
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx || nx >= r || 0 > ny || ny >= c || mask & (1 << (board[nx][ny] - 65))) {
            ans = max(ans, cnt);
            continue;
        }

        recur(nx, ny, mask, cnt + 1);
    }
}

int main(void) {
    cin >> r >> c;

    string s;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        for (int j = 0; j < c; ++j) {
            board[i][j] = s[j];
        }
    }

    recur(0, 0, 0, 1);

    cout << ans << '\n';
}
