#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define x first
#define y second

const int MAX = 100004;

int n, m, ans;
int arr[3];

int dis[MAX];
queue<int> q;
vector<function<int(int)>> f = {
    [](int x) { return x - 1; }, [](int x) { return x + 1; }, [](int x) { return x * 2; }
};

int main(void) {
    cin >> n >> m;

    q.push(n);
    dis[n] = 1;

    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == m) ans++;

        for (int i = 0; i < f.size(); ++i) {
            int nx = f[i](x);

            if (0 > nx || nx >= MAX) continue;
            if (dis[nx] != 0 && dis[nx] != dis[x] + 1) continue; // 이미 방문한적이 있더라도 최단 경로일 경우 카운트 해주기 위해
            dis[nx] = dis[x] + 1;

            q.push(nx);
        }
    }

    cout << dis[m] - 1 << '\n' << ans << '\n';
}
