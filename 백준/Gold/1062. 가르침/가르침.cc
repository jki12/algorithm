#include <bits/stdc++.h>

using namespace std;

#define SIZE 64

int n, k, ans;
int flags[SIZE];

void recur(int flag, int idx, int c) { // 26Ck
    if (c == k) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (flags[i] == (flags[i] & flag)) cnt++;
        }

        ans = max(ans, cnt);

        return;
    }

    if (idx >= 26) {
        return;
    }

    recur(flag | (1 << idx), idx + 1, c + 1);
    recur(flag, idx + 1, c);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;

    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;

        int flag = 0;
        for (int i = 0; i < s.size(); ++i) {
            flag |= (1 << (s[i] - 'a'));
        }

        flags[i] = flag;
    }
    
    recur(0, 0, 0);

    cout << ans << '\n';
}
