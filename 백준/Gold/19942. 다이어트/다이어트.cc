#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 16

struct nutrition {
    int p, f, s, v, c;
};

int min_cost = INT32_MAX;
int n, mp, mf, mv, ms, cost;

bool vis[SIZE];
bool ans[SIZE];
nutrition foods[SIZE];

void recur(int cur, int p, int f, int v, int s, int c) {
    if (mp <= p && mf <= f && mv <= v && ms <= s && min_cost > c) { // 조건문 하나로 수정.
        min_cost = c;
        copy(vis, vis + n, ans);

        return;
    }

    // for문 제거.
    if (cur < n) {
        vis[cur] = true;
        recur(cur + 1, foods[cur].p + p, foods[cur].f + f, foods[cur].v + v, foods[cur].s + s, foods[cur].c + c);
        vis[cur] = false;

        recur(cur + 1, p, f, v, s, c);
    }
}

int main(void) {
    cin >> n >> mp >> mf >> ms >> mv;

    for (int i = 0; i < n; ++i) {
        cin >> foods[i].p >> foods[i].f >> foods[i].s >> foods[i].v >> foods[i].c;
    }

    recur(0, 0, 0, 0, 0, 0);

    if (min_cost == INT32_MAX) {
        cout << -1;
    }
    else {
        cout << min_cost << ' ';
        for (int i = 0; i < n; ++i) {
            if (ans[i]) cout << i + 1 << ' ';
        }
    }
}
