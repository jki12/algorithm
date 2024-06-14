#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ans = INT32_MAX;
int board[50][50];

int h[100]; // home
int c[100]; // chicken

int* p;
int* q;
int temp[100];

void recur(int index, int start) {
    if (index == m) {
        int dis = 0;

        for (int i = 0; i < p - h; ++i) {
            int dis_min = INT32_MAX;

            for (int j = 0; j < index; ++j) {
                dis_min = min(abs(temp[j] / n - h[i] / n) + abs(temp[j] % n - h[i] % n), dis_min);
            }
            dis += dis_min;
        }

        ans = min(dis, ans);
    }

    for (int i = start; i < q - c; ++i) {
        temp[index] = c[i];

        recur(index + 1, i + 1);
    }
}

int main(void) {
    cin >> n >> m;

    p = h;
    q = c;
    int x;
    for (int i = 0 ; i < n * n; ++i) {
        cin >> x;
        board[i / n][i % n] = x;

        if (x == 1) {
            *p++ = i;
        }
        else if (x == 2) {
            *q++ = i;
        }
    }

    recur(0, 0);

    cout << ans << '\n';
}
