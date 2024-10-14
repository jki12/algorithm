#include <bits/stdc++.h>

using namespace std;

#define SIZE 1028

int n, k;
int arr[SIZE][SIZE];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
	    for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];

            arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
	    }
    }

    int x1, x2, y1, y2;
    while (k--) {
        cin >> x1 >> y1 >> x2 >> y2;

        cout << arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1] << '\n';
    }
}