#include <bits/stdc++.h>

using namespace std;

string a, b;
stack<char> st;
vector<char> temp;

string to_string() {
    string ret = "";

    while (st.size()) {
        ret += st.top(); st.pop();
    }
    reverse(ret.begin(), ret.end());

    return ret;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;

    int j = 0;
    for (int i = 0; i < a.size(); ++i) {
        char c = a[i];
        st.push(c);
        
        j = b.size();
        
        while (st.size() >= j && j && st.top() == b[j - 1]) {
            j--;
            temp.push_back(st.top()); st.pop();
        }

        if (j == 0) temp.clear();
        
        while (j && temp.size()) {
            st.push(temp.back()); temp.pop_back();
        }
    }

    a = to_string();

    cout << (a.size() ? a : "FRULA") << '\n';
}
