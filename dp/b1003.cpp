

#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

const int len = 41;

int t, n;
pair<int, int> table[len];

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	table[0] = { 1, 0 }; table[1] = { 0, 1 };

	for (int i = 2; i < len; ++i) {
		table[i] = { table[i - 1].X + table[i - 2].X, table[i - 1].Y + table[i - 2].Y };
	}

	cin >> t;
	while (t--) {
		cin >> n;

		cout << table[n].X << ' ' << table[n].Y << '\n';
	}

	return 0;
}