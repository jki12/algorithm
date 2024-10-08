#include <bits/stdc++.h>

using namespace std;

int n;

bool compare(string a, string b) {
    if (a.size() == b.size()) return (a.compare(b) < 0);

    return a.size() < b.size();
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    vector<string> v(n);
    vector<string> unique;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
        if (i == 0 || v[i] != v[i - 1]) unique.push_back(v[i]);

    sort(unique.begin(), unique.end(), compare);

    for (int i = 0; i < unique.size(); ++i) cout << unique[i] << '\n';
}