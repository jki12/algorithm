#include <bits/stdc++.h>

using namespace std;

#define SIZE 128

int n, l, ans;

int board[SIZE][SIZE];

int main(void) {
    cin >> n >> l;

    for (int i = 0; i < n * n; ++i) {
        cin >> board[i / n][i % n];
    }

    for (int i = 0; i < n; ++i) { // col.
        int h = board[i][0];

        int mark[SIZE] = { 0, };
        for (int j = 1; j < n; ++j) {

            if (abs(board[i][j] - h) > 1) goto next;
            if (board[i][j] == h) continue;

            int temp = l;
            if (h < board[i][j]) { // 높아진 경우.
                if (j - l < 0) goto next;

                while (temp) {
                    if (h != board[i][j - temp] || mark[j - temp]) goto next;

                    mark[j - temp] = true;
                    temp--;
                }
            }
            else if (h > board[i][j]) { // 낮아진 경우.
                if (j + l > n) goto next;

                while (temp--) { // 자신한테 설치 가능
                    if (board[i][j] != board[i][j + temp] || mark[j + temp]) goto next;
                    mark[j + temp] = true;
                }
            }

            h = board[i][j];
        }
        ans++;
    next:
        continue;
    }

    for (int i = 0; i < n; ++i) { // row.
        int h = board[0][i];

        int mark[SIZE] = { 0, };
        for (int j = 1; j < n; ++j) {

            if (abs(board[j][i] - h) > 1) goto next2;
            if (board[j][i] == h) continue;

            int temp = l;
            if (h < board[j][i]) { // 높아진 경우.
                if (j - l < 0) goto next2;

                while (temp) {
                    if (h != board[j - temp][i] || mark[j - temp]) goto next2;

                    mark[j - temp] = true;
                    temp--;
                }
            }
            else if (h > board[j][i]) { // 낮아진 경우.
                if (j + l > n) goto next2;

                while (temp--) {
                    if (board[j][i] != board[j + temp][i] || mark[j + temp]) goto next2;
                    mark[j + temp] = true;
                }
            }

            h = board[j][i];
        }
        ans++;
    next2:
        continue;
    }

    cout << ans << '\n';
}
