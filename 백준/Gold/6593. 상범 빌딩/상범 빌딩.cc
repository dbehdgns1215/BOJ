#include <bits/stdc++.h>
using namespace std;

int L, R, C;
char board[31][31][31];
bool vis[31][31][31];
int dist[31][31][31];

int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

bool is_find;

void reset() {
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < R; j++)
		{
			for (int k = 0; k < C; k++)
			{
				board[i][j][k] = 0;
				vis[i][j][k] = 0;
				dist[i][j][k] = 0;
			}
		}
	}
	is_find = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L >> R >> C;

	queue<tuple<int, int, int>> Q;

	while (L != 0 && R != 0 && C != 0)
	{
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S')
					{
						Q.push({ i, j, k });
						vis[i][j][k] = 1;
						dist[i][j][k] = 0;
					}
				}
			}
		}

		while (!Q.empty())
		{
			int l, r, c;
			tie(l, r, c) = Q.front(); Q.pop();

			for (int dir = 0; dir < 6; dir++)
			{
				int nx = r + dx[dir];
				int ny = c + dy[dir];
				int nz = l + dz[dir];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L) continue;
				if (vis[nz][nx][ny] || board[nz][nx][ny] == '#') continue;
				if (board[nz][nx][ny] == 'E') {
					is_find = 1;
					cout << "Escaped in " << dist[l][r][c] + 1 << " minute(s).\n";
					while (!Q.empty())
					{
						Q.pop();
					}
					break;
				}
				vis[nz][nx][ny] = 1;
				dist[nz][nx][ny] = dist[l][r][c] + 1;
				Q.push({ nz, nx, ny });
			}
		}

		if (!is_find) {
			cout << "Trapped!\n";
		}

		reset();
		cin >> L >> R >> C;
	}
}