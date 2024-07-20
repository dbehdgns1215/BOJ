#include <bits/stdc++.h>
using namespace std;

int board[26][26];
int vis[26][26];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	queue<pair<int, int>> Q;
	vector<int> ans;

	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < n; j++) {
			board[i][j] = row[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 1 && vis[i][j] == 0)
			{
				int size = 1;
				Q.push({ i, j });
				vis[i][j] = 1;

				while (!Q.empty())
				{
					auto cur = Q.front(); Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny>=n) continue;
						if (vis[nx][ny] || board[nx][ny] == 0) continue;

						vis[nx][ny] = 1;
						Q.push({ nx, ny });
						size++;
					}
				}
				ans.push_back(size);
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
	sort(ans.begin(), ans.end());
	for (auto a : ans)
	{
		cout << a << "\n";
	}
}

