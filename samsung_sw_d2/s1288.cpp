#include <bits/stdc++.h>

using namespace std;

const int len = 10;

int arr[len];
int t, n;

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;

        cout << '#' << i << ' ';

        int count = 1;
        memset(arr, 0, sizeof(arr));

        for (int i = 1; ; ++i) {
            // verify
            int temp = n * i;
            while (temp != 0) {
                arr[temp % 10]++;

                temp /= 10;
            }

            int count = 0;
            for (int j = 0; j < 10; ++j) {
                if (arr[j] == 0) break;

                count++;
            }

            if (count == len) {
                cout << n * i;

                break;
            }
        }

        cout << '\n';
    }

    return 0;
}