#include <bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, 0, 0, 1, -1 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 1, -1, 0, 0, 0, 0 };

const int len = 31;

int x, y, z;
char board[len][len][len];
int dist[len][len][len];

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	queue<tuple<int, int, int>> q;

	while (true) {
		bool can_exit = false;

		cin >> z >> x >> y;

		if (x == 0 && y == 0 && z == 0) return 0; // exit condition.

		while (!q.empty()) q.pop(); // q.clear();
		memset(dist, 0, sizeof(dist));

		for (int i = 0; i < z; ++i) {
			for (int j = 0; j < x; ++j) {
				for (int k = 0; k < y; ++k) {
					cin >> board[i][j][k];

					if (board[i][j][k] == 'S') {
						q.push(make_tuple(i, j, k));

						dist[i][j][k] = 1;
					}
				}
			}
		}

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			for (int i = 0; i < 6; ++i) {
				int nz = get<0>(cur) + dz[i];
				int nx = get<1>(cur) + dx[i];
				int ny = get<2>(cur) + dy[i];

				if (0 > nz || z <= nz || 0 > nx || x <= nx || 0 > ny || y <= ny || board[nz][nx][ny] == '#' || dist[nz][nx][ny] != 0) continue;

				dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				q.push(make_tuple(nz, nx, ny));

				if (board[nz][nx][ny] == 'E') {
					can_exit = true;
					cout << "Escaped in " << dist[nz][nx][ny] - 1 << " minute(s)." << '\n';

					goto next;
				}
			}
		}
	next:
		if (!can_exit) cout << "Trapped!" << '\n';
	}

	return 0;
}