#include <bits/stdc++.h>
using namespace std;

int n;
char board[101][101];
int vis[101][101];
int vis2[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int normal_cnt;
int rg_blind_cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}

	queue<pair<int, int>> normal_Q;
	queue<pair<int, int>> rgBlind_Q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j] && board[i][j] == 'R')
			{
				vis[i][j] = 1;
				normal_Q.push({ i, j });

				while (!normal_Q.empty())
				{
					auto cur = normal_Q.front(); normal_Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] || board[nx][ny] != 'R') continue;
						vis[nx][ny] = 1;
						normal_Q.push({ nx, ny });
						
					}
				}
				normal_cnt++;

			}
			else if (!vis[i][j] && board[i][j] == 'G')
			{
				vis[i][j] = 1;
				normal_Q.push({ i, j });

				while (!normal_Q.empty())
				{
					auto cur = normal_Q.front(); normal_Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] || board[nx][ny] != 'G') continue;
						normal_Q.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}
				normal_cnt++;
			}
			else if (!vis[i][j] && board[i][j] == 'B')
			{
				vis[i][j] = 1;
				normal_Q.push({ i, j });

				while (!normal_Q.empty())
				{
					auto cur = normal_Q.front(); normal_Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] || board[nx][ny] != 'B') continue;
						normal_Q.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}
				normal_cnt++;
			}
		}
	}

	cout << normal_cnt << "\n";

	// 적록색약 -> 적색과 녹색의 구별이 불가능. G를 R로 전부 치환
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'G')
			{
				board[i][j] = 'R';
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis2[i][j] && board[i][j] == 'R')
			{
				vis2[i][j] = 1;
				rgBlind_Q.push({ i, j });

				while (!rgBlind_Q.empty())
				{
					auto cur = rgBlind_Q.front(); rgBlind_Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis2[nx][ny] || board[nx][ny] != 'R') continue;
						vis2[nx][ny] = 1;
						rgBlind_Q.push({ nx, ny });

					}
				}
				rg_blind_cnt++;

			}
			else if (!vis2[i][j] && board[i][j] == 'B')
			{
				vis2[i][j] = 1;
				rgBlind_Q.push({ i, j });

				while (!rgBlind_Q.empty())
				{
					auto cur = rgBlind_Q.front(); rgBlind_Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis2[nx][ny] || board[nx][ny] != 'B') continue;
						rgBlind_Q.push({ nx, ny });
						vis2[nx][ny] = 1;
					}
				}
				rg_blind_cnt++;
			}
		}
	}

	cout << rg_blind_cnt++;
}