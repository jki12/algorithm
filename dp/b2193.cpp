#include <bits/stdc++.h>

using namespace std;

const int len = 91;

int n;
long long int zero[len], one[len]; // 마지막에 오는 숫자

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	zero[1] = 0; one[1] = 1;
	zero[2] = 1; one[2] = 0;

	for (int i = 3; i <= n; ++i) {
		zero[i] = zero[i - 1] + one[i - 1];
		one[i] = zero[i - 1];
	}

	cout << zero[n] + one[n];

	return 0;
}