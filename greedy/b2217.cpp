#include <iostream>
#include <algorithm>

using namespace std;

const int len = 51;

int n, ans;
int a[len];
int b[len];

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	sort(a, a + n, greater<int>());
	sort(b, b + n);

	for (int i = 0; i < n; ++i) {
		ans += a[i] * b[i];
	}

	cout << ans;

	return 0;
}