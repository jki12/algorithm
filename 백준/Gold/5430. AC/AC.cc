#include <iostream> // #include <bits/stdc++.h>
#include <deque>

using namespace std;

int t, n, e, mod;
deque<string> dq;

void print() {
    if (e) cout << "error";
    else {
        cout << '[';
        while (!dq.empty()) {
        if (!mod) {
            cout << dq.front(); dq.pop_front();
        }
        else {
            cout << dq.back(); dq.pop_back();
        }

        if (!dq.empty()) cout << ",";
        }
        cout << ']';
    }

    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;

    string cmd, arr;
    for (int i = 0; i < t; ++i) {
        e = 0;
        mod = 0;

        cin >> cmd >> n >> arr;

        for (int i = 1; i < arr.size() - 1; ++i) { // skip '[', ']'
            int idx = min(arr.find(',', i), arr.size() - 1); // 못 찾을 경우 -1이 아닌 SIZE_T_MAX를 반환.

            dq.push_back(arr.substr(i, idx - i));
            i = idx;
        }

        for (int j = 0; j < cmd.size(); ++j) {
            if (cmd[j] == 'R') mod ^= 1;
            else if (dq.empty()) {
                e = 1;
                break;
            } // cout or flag.
            else {
                if (!mod) dq.pop_front();
                else dq.pop_back();
            }
        }

        print();
    }
}
