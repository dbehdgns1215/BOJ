#include <bits/stdc++.h>
using namespace std;

int board[501][501];
int n, m;
queue <pair<int, int>> Q;
queue <pair<int, int>> ready;
bool vis[501][501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cnt = 0;
int max_size = 0;

int bfs(int i, int j) {
	vis[i][j] = 1;
	board[i][j] = 0;
	Q.push({ i, j });
	int size = 0;
	while (!Q.empty())
	{
		size++;
		pair <int, int> cur = Q.front(); Q.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;

			vis[nx][ny] = 1;
			Q.push({ nx, ny });
			board[nx][ny] = 0;
		}
	}

	return size;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int size = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;

			board[i][j] = temp;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1)
			{
				size = bfs(i, j);
				if (size > max_size)
				{
					max_size = size;
				}
				cnt++;
			}
		}
	}

	cout << cnt << "\n" << max_size;
}

