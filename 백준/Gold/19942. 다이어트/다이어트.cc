#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 16

struct nutrition {
    int p, f, s, v, c;
};

int min_cost = INT32_MAX;
int n, mp, mf, mv, ms, p, f, v, s, cost;

bool vis[SIZE];
bool ans[SIZE];
nutrition foods[SIZE];

void recur(int cur) {
    if (mp <= p && mf <= f && mv <= v && ms <= s) {

        if (min_cost > cost) {
            min_cost = cost;
            copy(vis, vis + n, ans);
        }

        return;
    }

    for (int i = cur; i < n; ++i) {
        if (vis[i]) continue;

        vis[i] = true;
        p += foods[i].p;
        f += foods[i].f;
        v += foods[i].v;
        s += foods[i].s;
        cost += foods[i].c;
        
        recur(i + 1);

        vis[i] = false;
        p -= foods[i].p;
        f -= foods[i].f;
        v -= foods[i].v;
        s -= foods[i].s;
        cost -= foods[i].c;
    }
}

int main(void) {
    cin >> n >> mp >> mf >> ms >> mv;

    for (int i = 0; i < n; ++i) {
        nutrition temp;

        cin >> temp.p;
        cin >> temp.f;
        cin >> temp.s;
        cin >> temp.v;
        cin >> temp.c;

        foods[i] = temp;
    }

    recur(0);

    if (min_cost == INT32_MAX) {
        cout << -1;
        return 0;
    }

    cout << min_cost << ' ';
    for (int i = 0; i < n; ++i) {
        if (ans[i]) cout << i + 1 << ' ';
    }
}
