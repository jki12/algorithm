#include <iostream> // #include <bits/stdc++.h>
#include <algorithm>
#include <queue>

using namespace std;

long ans;
int n, m, v;
int arr[1000001], count1[10001];
priority_queue<int> q;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    while (n--) {
        cin >> m;

        for (int i = 0; i < m; ++i) {
            cin >> v;

            arr[i] = v;
            count1[v]++;
            q.push(v);
        }

        int cnt = 0;
        int sum = 0;

        for (int i = 0; i < m; ++i) {
            v = arr[i];

            count1[v]--;
            if (v < q.top()) { // 매입.
                cnt++;
                sum += v;
            }
            else if (v == q.top()) { // 익절.
                ans += (arr[i] * cnt) - sum;

                while (q.size() && (count1[q.top()] == 0)) q.pop();
                cnt = 0;
                sum = 0;
            }
        }

        cout << ans << '\n';

        while (q.size()) q.pop(); ans = 0;
    }
}
