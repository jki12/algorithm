#include <iostream>

using namespace std;

const int len = 1000001;

int n;
int board[len];

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 2; i <= n; ++i) {
		board[i] = board[i - 1] + 1;

		if (i % 2 == 0) board[i] = min(board[i], board[i / 2] + 1);
		if (i % 3 == 0) board[i] = min(board[i], board[i / 3] + 1);
	}

	int count = board[n];
	cout << count << '\n' << n << ' ';

	while (n != 1) {
		count--;

		if (board[n - 1] == count) n -= 1;
		else if (n % 2 == 0 && board[n / 2] == count) n /= 2;
		else if (n % 3 == 0 && board[n / 3] == count) n /= 3;

		cout << n << ' ';
	}

	return 0;
}

// counter ex) answer : 33, 33 16 8 4 2 1 / wrong : 33 16 8 4 2 1