#include <bits/stdc++.h>

#define SIZE (100001)
#define ll long long int

using namespace std;

ll n, m, ans;
int arr[SIZE];
bool vis[SIZE];

queue<int> q;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        m = arr[i];

        while (vis[m]) {
            vis[q.front()] = 0;
            q.pop();
        }

        q.push(m);
        vis[m] = 1;

        ans += q.size();
    }

    cout << ans << '\n';
}
