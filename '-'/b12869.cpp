#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define x first
#define y second

const int MAX = 61;

int n, ans;
int arr[3];
int vis[MAX][MAX][MAX];

struct node {
    int a, b, c;

    node(int a, int b, int c) : a(a), b(b), c(c) {}
};

queue<node> q;

void bfs() {
    q.push(node(arr[0], arr[1], arr[2]));
    vis[arr[0]][arr[1]][arr[2]] = 1;

    while (!q.empty() && !vis[0][0][0]) {
        node _node = q.front(); q.pop(); // to poll.

        vector<int> dmg { 9, 3, 1 };
        do {
            int a = max(_node.a - dmg[0], 0);
            int b = max(_node.b - dmg[1], 0);
            int c = max(_node.c - dmg[2], 0);

            if (vis[a][b][c]) continue;

            vis[a][b][c] = vis[_node.a][_node.b][_node.c] + 1;
            q.push(node(a, b, c));

        } while(prev_permutation(dmg.begin(), dmg.end()));
    }
}

int main(void) {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    bfs();
    cout << vis[0][0][0] - 1 << '\n';
}
