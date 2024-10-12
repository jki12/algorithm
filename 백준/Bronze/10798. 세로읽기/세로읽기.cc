#include <bits/stdc++.h>

using namespace std;

int n = 5;

int main(void) {
    deque<string> dq;

    string s;
    while (n--) {
        cin >> s;

        dq.push_back(s);
    }

    int cur = 0;
    while (dq.size()) {
        int cnt = dq.size();

        for (int i = 0; i < cnt; ++i) {
            string s = dq.front(); dq.pop_front();

            cout << s[cur];
            if (cur < s.length() - 1) dq.push_back(s);
        }

        cur++;
    }
}