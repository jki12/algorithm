#include <bits/stdc++.h>

using namespace std;

#define SIZE 256

int n, k, ans;
string s;
int word_flags[SIZE];

void recur(int flag, int idx, int c) { // 26Ck
    if (c == k) {
        int temp = 0;
        for (int i = 0; i < n; ++i) {
            if (word_flags[i] == (word_flags[i] & flag)) temp++;
        }

        ans = max(ans, temp);

        return;
    }

    for (int i = idx; i < 26; ++i) {
        recur(flag | (1 << i), i + 1, c + 1);
    }
}

int main(void) {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> s;

        int flag = 0;
        for (int i = 0; i < s.size(); ++i) {
            flag |= (1 << (s[i] - 'a'));
        }

        word_flags[i] = flag;
    }

    
    recur(0, 0, 0);

    cout << ans << '\n';
}
