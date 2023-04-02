#include <iostream>

using namespace std;

const int len = 12;

int n;
int board[len];

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	board[1] = 1;
	// 2, 3 窍唱肺 备己等 版快 + 1
	board[2] = board[1] + 1;
	board[3] = board[1] + board[2] + 1;

	for (int i = 4; i < len; ++i) {
		board[i] = board[i - 1] + board[i - 2] + board[i - 3];
	}

	int temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;

		cout << board[temp] << '\n';
	}

	return 0;
}