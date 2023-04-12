#include <bits/stdc++.h>

using namespace std;

const int len = 5004;

int n, ans;
int arr[len];

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	arr[3] = 1; arr[4] = -1; arr[5] = 1; arr[6] = 2; arr[7] = -1;

	for (int i = 8; i <= n; ++i) {
		if (arr[i - 5] == -1 && arr[i - 3] == -1) arr[i] = -1;
		else if (arr[i - 5] == -1) arr[i] = arr[i - 3] + 1;
		else if (arr[i - 3] == -1) arr[i] = arr[i - 5] + 1;
		else arr[i] = min(arr[i - 3], arr[i - 5]) + 1;
	}

	cout << arr[n];

	return 0;
}