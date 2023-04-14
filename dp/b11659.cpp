#include <bits/stdc++.h>

using namespace std;

const int len = 100001;

int n, m, i, j;
int arr[len];
int table[len];

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];

		table[i] = table[i - 1] + arr[i];
	}

	for (int k = 0; k < m; ++k) {
		cin >> i >> j;

		cout << table[j] - table[i - 1] << '\n';
	}

	return 0;
}