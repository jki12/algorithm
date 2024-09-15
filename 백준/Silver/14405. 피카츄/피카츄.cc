#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    bool res = true;
    for (int i = 0; i < s.size(); ++i) {
        if (i == s.size() - 1 || s[i] == 'c' && i == s.size() - 2) res = false;
        else if (s[i] == 'p' && s[i + 1] == 'i') ++i;
        else if (s[i] == 'k' && s[i + 1] == 'a') ++i;
        else if (s[i] == 'c' && s[i + 1] == 'h' && s[i + 2] == 'u') i += 2;
        else { res = false; break; }
    }

    cout << (res ? "YES" : "NO") << '\n';
}
