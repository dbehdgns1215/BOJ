#include <bits/stdc++.h>
using namespace std;

int n, m;
string maze[101];
int dist[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}
	
	dist[0][0] = 1;
	q.push({ 0, 0 });
	
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] > 0 || maze[nx][ny] == '0') continue;

			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}	
	}

	cout << dist[n - 1][m - 1];
}