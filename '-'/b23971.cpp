#include <bits/stdc++.h>

using namespace std;

int r, c, n, m;

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> r >> c >> n >> m;

	cout << (int) ceil(r / (float)(1 + n)) * (int) ceil(c / (float)(1 + m));

	return 0;
}