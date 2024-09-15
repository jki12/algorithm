#include <iostream>
#include <stack>

using namespace std;

string a, b;

string make_padding(int n) {
    string s;

    for (int i = 0; i < n; ++i) s+= '0';

    return s;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;

    int size = a.size() - b.size();

    if (size <= 0) a = make_padding(abs(size)) + a;
    else b = make_padding(size) + b;


    stack<int> st;
    int c = 0; // carry.
    for (int i = a.size() - 1; i >= 0; --i) {
        int n = (a[i] - '0') + (b[i] - '0') + c;

        c = n / 10;
        st.push(n % 10);
    }

    if (c) st.push(c);

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}
