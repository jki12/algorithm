#include <bits/stdc++.h>
 
using namespace std;
 
int t, n, k;
char c;
 
int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
 
        cout << '#' << i;
 
        int temp = 0;
        for (int j = 0; j < n; ++j) {
            cin >> c >> k;
 
            for (int m = 0; m < k; ++m) {
                if (temp % 10 == 0) cout << '\n';
 
                cout << c;
 
                temp++;
            }
        }
         
        cout << '\n';
    }
 
    return 0;
}