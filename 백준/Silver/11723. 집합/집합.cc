#include <bits/stdc++.h>

using namespace std;

int n, x, flag;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    string c;
    for (int i = 0; i < n; ++i) {
        cin >> c;

        if (c.compare("all") == 0) {
            flag = ~0;
        }
        else if (c[0] == 'e') {
            flag = 0;
        }
        else {
            cin >> x;

            if (c[0] == 'a') flag |= (1 << x);
            if (c[0] == 'r') flag &= ~(1 << x);
            if (c[0] == 't') flag ^= (1 << x);
            if (c[0] == 'c') cout << ((flag & (1 << x)) != 0) << ' ';
        }
    }
}
