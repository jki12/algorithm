#include <bits/stdc++.h>

using namespace std;

const int len = 21;

int n, ans;
int board[len][len];

// int dir[5]; for debug.

void move(const int dir) {

	if (dir == 3) { // left shift.
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n - 1; ++j) {

				for (int k = j + 1; k < n; ++k) {
					if (board[i][j] != 0 && board[i][k] != 0 && board[i][j] != board[i][k]) break;
					if (board[i][j] == 0 && board[i][j] != board[i][k]) {

						// swap.
						board[i][j] = board[i][k];
						board[i][k] = 0;

						j--;

						break;
					}
					else if (board[i][j] == 0 && board[i][j] == board[i][k]) continue;
					else if (board[i][j] == board[i][k]) {
						board[i][j] *= 2;
						board[i][k] = 0;

						break;
					}
				}
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = n - 1; j > 0; --j) {

				for (int k = j - 1; k >= 0; --k) {
					if (board[i][j] != 0 && board[i][k] != 0 && board[i][j] != board[i][k]) break;
					if (board[i][j] == 0 && board[i][j] != board[i][k]) {

						// swap.
						board[i][j] = board[i][k];
						board[i][k] = 0;

						j++;

						break;
					}
					else if (board[i][j] == 0 && board[i][j] == board[i][k]) continue;
					else if (board[i][j] == board[i][k]) {
						board[i][j] *= 2;
						board[i][k] = 0;

						break;
					}
					
				}
			}
		}
	}
	else if (dir == 2) {
		for (int j = 0; j < n; ++j) {
			for (int i = n - 1; i > 0; --i) {

				for (int k = i - 1; k >= 0; --k) {
					if (board[i][j] != 0 && board[k][j] != 0 && board[i][j] != board[k][j]) break;
					if (board[i][j] == 0 && board[i][j] != board[k][j]) {

						// swap.
						board[i][j] = board[k][j];
						board[k][j] = 0;

						i++;

						break;
					}
					else if (board[i][j] == 0 && board[i][j] == board[k][j]) continue;
					else if (board[i][j] == board[k][j]) {
						board[i][j] *= 2;
						board[k][j] = 0;

						break;
					}
				}
			}
		}
	}
	else if (dir == 0) {
		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < n - 1; ++i) {

				for (int k = i + 1; k < n; ++k) {
					if (board[i][j] != 0 && board[k][j] != 0 && board[i][j] != board[k][j]) break;
					if (board[i][j] == 0 && board[i][j] != board[k][j]) {

						// swap.
						board[i][j] = board[k][j];
						board[k][j] = 0;

						i--;

						break;
					}
					else if (board[i][j] == 0 && board[i][j] == board[k][j]) continue;
					else if (board[i][j] == board[k][j]) {
						board[i][j] *= 2;
						board[k][j] = 0;

						break;
					}
				}
			}
		}
	}

}

void dfs(const int k)
{
	if (k == 5) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans = max(ans, board[i][j]);
			}
		}

		return;
	}

	int copy[len][len]; // backup.
	memcpy(copy, board, sizeof(copy));

	for (int i = 0; i < 4; ++i) {
		move(i);
		dfs(k + 1);
		memcpy(board, copy, sizeof(board)); // reset.
	}
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	dfs(0);
	cout << ans;

	return 0;
}