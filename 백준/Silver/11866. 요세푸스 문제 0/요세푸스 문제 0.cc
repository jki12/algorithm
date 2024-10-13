#include <bits/stdc++.h>

using namespace std;

queue<int> q, r;
int n, k;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) q.push(i);

    int idx = 1;
    while (q.size()) {
        int cur = q.front(); q.pop();

        if (idx % k == 0) r.push(cur);
        else q.push(cur);

        idx++;
    }

    cout << '<';
    while (r.size()) {
        cout << r.front(); r.pop();

        if (r.size()) cout << ", ";
    }
    cout << '>';
}