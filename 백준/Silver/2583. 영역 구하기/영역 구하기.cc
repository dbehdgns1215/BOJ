#include <bits/stdc++.h>
using namespace std;

int m, n, k; // m 높이, n 넓이
int board[101][101];
bool vis[101][101];
int dist[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 }; 

int cnt;
vector <int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> k;

	// 사각형 채우기
	for (int i = 0; i < k; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int k = y1; k < y2; k++)
		{
			for (int o = x1; o < x2; o++)
			{
				board[k][o] = 1;
			}
		}
	}
	queue<pair<int, int>> Q;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j] && board[i][j] == 0)
			{
				int area = 1;
				cnt++;
				Q.push({ i, j });
				vis[i][j] = 1;

				while (!Q.empty())
				{
					auto cur = Q.front(); Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] || board[nx][ny]) continue;

						area++;
						Q.push({ nx, ny });
						vis[nx][ny] = 1; 
					}
				}
				ans.push_back(area);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt << "\n";
	for (auto a : ans)
	{
		cout << a << " ";
	}
}