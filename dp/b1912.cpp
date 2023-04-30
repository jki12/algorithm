#include <bits/stdc++.h>

using namespace std;

const int len = 100004;

int n;
int arr[len], table[len];

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; ++i) {
		table[i] = max(arr[i], table[i - 1] + arr[i]);
	}

	cout << *max_element(table + 1, table + n + 1); // O(n)

	return 0;
}