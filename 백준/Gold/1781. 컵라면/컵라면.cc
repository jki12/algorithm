#include <bits/stdc++.h>

using namespace std;

#define SIZE 200001
#define x first
#define y second

int n, p, d, ans;
pair<int, int> arr[SIZE];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> d >> p;

        arr[i] = { d, p };
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; ++i) {
        if (pq.size() < arr[i].x) pq.push(arr[i].y);
        else if (pq.top() < arr[i].y) {
            pq.pop();
            pq.push(arr[i].y);
        }
    }

    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << '\n';
}
