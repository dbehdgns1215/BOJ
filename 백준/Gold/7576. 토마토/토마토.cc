#include <bits/stdc++.h>
using namespace std;

int board[1002][1002];
int day[1002][1002];

int n, m;

queue <pair<int, int>> Q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++)
		{
			cin >> board[i][k];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++)
		{
			if (board[i][k] == 1)
			{
				Q.push({ i, k });
			}
			else if (board[i][k] == 0)
			{
				day[i][k] = -1;
			}
		}
	}

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (day[nx][ny] >= 0) continue;

			day[nx][ny] = day[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++)
		{
			if (day[i][k] == -1)
			{
				cout << -1;
				return 0;
			}
			ans = max(ans, day[i][k]);
		}
	}
	cout << ans;
}