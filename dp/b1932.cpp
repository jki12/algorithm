#include <bits/stdc++.h>

using namespace std;

const int len = 502;

int n;
int arr[len][len], table[len][len];

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> arr[i][j];
		}
	}

	table[0][0] = arr[0][0];

	int ans = table[0][0]; // n이 1일 경우.

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j - 1 >= 0) table[i][j] = max(table[i][j], arr[i][j] + table[i - 1][j - 1]);

			table[i][j] = max(table[i][j], arr[i][j] + table[i - 1][j]);

			ans = max(ans, table[i][j]);
		}
	}

	cout << ans;

	return 0;
}