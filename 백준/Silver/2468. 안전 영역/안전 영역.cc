#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int cnt;
int max_cnt;

void reset() {
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			vis[i][j] = 0;
		}
	}
	cnt = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> Q;


	for (int i = 0; i < 101; i++)
	{
		reset();

		for (int h = 0; h < n; h++)
		{
			for (int w = 0; w < n; w++)
			{
				if (board[h][w] > i && !vis[h][w])
				{
					
					Q.push({ h, w });
					vis[h][w] = 1;

					while (!Q.empty())
					{
						auto cur = Q.front(); Q.pop();

						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];

							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (vis[nx][ny] || board[nx][ny] <= i) continue;

							Q.push({ nx, ny });
							vis[nx][ny] = 1;

						}
					}

					cnt++;
				}
			}
		}
		if (max_cnt < cnt) max_cnt = cnt;
	}

	cout << max_cnt;
}