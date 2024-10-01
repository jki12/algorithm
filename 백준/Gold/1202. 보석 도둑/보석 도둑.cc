#include <bits/stdc++.h>

using namespace std;

#define SIZE 300001
#define ll long long int
#define x first
#define y second

int n, k, a;
ll ans;
pair<int, int> arr[SIZE];
int bag[SIZE];

priority_queue<int> pq;

int main(void) {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> arr[i].x >> arr[i].y;
    for (int i = 0; i < k; ++i) cin >> bag[i];

    sort(arr, arr + n);
    sort(bag, bag + k);

    int cur = 0;
    for (int i = 0; i < k; ++i) {
        while (cur < n && bag[i] >= arr[cur].x) { pq.push(arr[cur].y); cur++; }
        
        if (pq.size()) { ans += pq.top(); pq.pop(); }
    }

    cout << ans << '\n';
}
