#include <bits/stdc++.h>

using namespace std;

int a, b;
string s;
vector<int> v;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> s;

    for (int j = 0; j < s.size(); ++j) {
        char c = s[j];

        if (v.empty() || v.back() != c) {
            v.push_back(c);

            if (c == '0') a++;
            else b++;
        }
    }

    cout << min(a, b) << '\n';
}
