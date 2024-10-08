#include <iostream>

using namespace std;

int n, m;

int main(void) {
    cin >> n;

    while (n--) {
        cin >> m;

        while (m--) cout << '=';

        cout << '\n';
    }
}