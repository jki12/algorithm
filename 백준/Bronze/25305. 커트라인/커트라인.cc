#include <bits/stdc++.h>

using namespace std;

int n, k;

int main(void) {
    cin >> n >> k;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    cout << v[v.size() - k] << '\n';
}