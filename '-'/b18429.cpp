#include <bits/stdc++.h>

using namespace std;

const int len = 20;

int t, n;
int arr[len];

void swap(const int i, const int j)
{
	int temp = arr[i];

	arr[i] = arr[j];
	arr[j] = temp;
}

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < len; ++i) cin >> arr[i]; // input.

		int steps = 0;
		for (int i = 0; i < len; ++i) {
			int index = -1;

			for (int j = 0; j < i; ++j) { // 가장 앞에 있으며, arr[i]보다 큰 값을 찾는 과정.
				if (arr[i] < arr[j]) {
					index = j;

					break;
				}
			}

			if (index == -1) continue;

			for (int j = i; j > index; --j) {
				steps++;
				swap(j, j - 1);
			}
		}

		cout << n << ' ' << steps << '\n';
	}

	return 0;
}