#include <bits/stdc++.h>

using namespace std;

const int len = 100001;

int n, ans;
int arr[len];

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr, arr + n, greater<int>());


	for (int i = 0; i < n; ++i) {
		ans = max(ans, arr[i] * (i + 1));
	}

	cout << ans;

	return 0;
}

// 도움이 되었던 예) n = 3, 100 40 39 ans : 117, wrong : 100