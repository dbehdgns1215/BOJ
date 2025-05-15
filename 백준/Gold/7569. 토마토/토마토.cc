#include <bits/stdc++.h>
using namespace std;

int h, n, m;
int tomato[101][101][101];
int dist[101][101][101];

int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

queue<tuple<int, int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];

				if (tomato[i][j][k] == 1) { // tomato[h][n][m] tomato[dz][dx][dy]
					dist[i][j][k] = 0;
					q.push(tie(i, j, k));
				}
				if (tomato[i][j][k] == 0) {
					dist[i][j][k] = -1;
				}
			}
		}
	}

	while (!q.empty()) {
		int x, y, z;
		tie(z, x, y) = q.front(); q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nx = dx[dir] + x;
			int ny = dy[dir] + y;
			int nz = dz[dir] + z;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (dist[nz][nx][ny] >= 0) continue;

			dist[nz][nx][ny] = dist[z][x][y] + 1;
			q.push(tie(nz, nx, ny));
		}
	}

	int days = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				days = max(days, dist[i][j][k]);
			}
		}
	}

	cout << days;
}