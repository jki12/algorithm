#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int n, x;
ll ans;
stack<int> s;
map<int, int> m;

void push(int x) {
    m[x]++;
    s.push(x);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;

        if (s.empty()) push(x);
        else if (s.top() > x) {
            push(x);
            ans++;
        }
        else if (s.top() == x) {
            ans += m[x];
            m[x]++;
            
            if (s.size() > 1) ans++; // ex) { 4, 2, 2 },  x = 2일 경우 4랑도 쌍을 이룰 수 있어 +1을 해준다.
        }
        else {
            while (!s.empty() && s.top() < x) {
                int k = s.top(); s.pop();

                ans += m[k];
                m[k] = 0;
            }

            if (!s.empty()) {
                if (s.top() == x) {
                    ans += m[x];
                    if (s.size() > 1) ans++;

                    m[x]++;
                    continue;
                }
                else ans++;
            }

            push(x);
        }
    }

    cout << ans << '\n';
}
