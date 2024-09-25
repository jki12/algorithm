#include <bits/stdc++.h>

using namespace std;

int n, m, ans, z;
vector<int> v1;
vector<int> v2;

int s(vector<int> v) {
    int sum =0;

    for (int i = 0; i < v.size(); ++i) {
        if (i < v.size() - 1) {
            sum += (v[i] * v[i + 1]);
            i++;
        }
        else {
            sum += v[i];
        }
    }

    return sum;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> m;

        if (m == 0) z++;
        else if (m == 1) ans++;
        else if (m > 0) v1.push_back(m);
        else v2.push_back(m);
    }

    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end());

    if (z && v2.size() % 2 == 1) v2.pop_back(); // 음수의 개수가 홀수면 (0 * -n)해서 0으로 만듬
    
    ans += s(v1) + s(v2);

    cout << ans << '\n';
}
