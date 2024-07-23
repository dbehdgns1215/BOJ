#include <bits/stdc++.h>
using namespace std;

int h, n, m;
int tomato[101][101][101];
int dist[101][101][101];
bool vis[101][101][101];

int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> h;

	queue<tuple<int, int, int>> Q;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++) 
			{
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)
				{
					Q.push({ i, j, k });
					vis[i][j][k] = 1;
					dist[i][j][k] = 0;
				}
				if (tomato[i][j][k] == 0)
				{
					dist[i][j][k] = -1;
				}
			}
		}
	}

	if (Q.empty()) {
		cout << -1;
		return 0;
	}

	while (!Q.empty())
	{
		int x, y, z;
		tie(z, x, y) = Q.front(); Q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nz = z + dz[dir];

			if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nz][nx][ny] || tomato[nz][nx][ny] == -1) continue;

			dist[nz][nx][ny] = dist[z][x][y] + 1;
			vis[nz][nx][ny] = 1;
			Q.push({ nz, nx, ny });
		}
	}

	int ans = 0;
	
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (dist[i][j][k] == -1)
				{
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	cout << ans;
	
}