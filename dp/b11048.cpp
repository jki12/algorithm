#include <bits/stdc++.h>

using namespace std;

const int len = 1001;

int n, m;
int board[len][len];
int dist[len][len];

bool is_invalid(int i, int j)
{
	return (0 <= i && i < n && 0 <= j && j < m);
}

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	memcpy(dist, board, sizeof(dist));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (is_invalid(i + 1, j + 1)) dist[i + 1][j + 1] = max(dist[i + 1][j + 1], dist[i][j] + board[i + 1][j + 1]);
			if (is_invalid(i + 1, j)) dist[i + 1][j] = max(dist[i + 1][j], dist[i][j] + board[i + 1][j]);
			if (is_invalid(i, j + 1)) dist[i][j + 1] = max(dist[i][j + 1], dist[i][j] + board[i][j + 1]);
		}
	}

	cout << dist[n - 1][m - 1];

	return 0;
}