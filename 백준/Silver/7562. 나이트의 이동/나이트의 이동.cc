#include <bits/stdc++.h>
using namespace std;

int vis[301][301];
int dist[301][301];

int dx[8] = { 2, 2, 1, -1, -2, -2, -1, 1};
int dy[8] = { 1, -1, 2, 2 , -1, 1, -2, -2};

int t, l;
int x, y;
int x2, y2;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);
	
	cin >> t;
	queue<pair<int, int>> Q;

	for (int i = 0; i < t; i++)
	{
		for (int i = 0; i < 301; i++)
		{
			for (int j = 0; j < 301; j++)
			{
				vis[i][j] = 0;
				dist[i][j] = 0;
			}
		}

		cin >> l;

		cin >> x >> y;
		cin >> x2 >> y2;

		

		
		vis[x][y] = 1;
		vis[x2][y2] = -1; // 목표지점을 -1로 설정

		Q.push({ x, y });
		if (x == x2 && y == y2) {
			cout << "0\n"; Q.pop();
		}

		while (!Q.empty())
		{
			auto cur = Q.front(); Q.pop();

			for (int dir = 0; dir < 8; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
				if (vis[nx][ny] && vis[nx][ny] != -1) continue;
				if (vis[nx][ny] == -1) {
					cout << dist[cur.first][cur.second] + 1<< "\n";
					while (!Q.empty()) Q.pop(); // 큐 비우기
					break; // 내부 for 루프 탈출
				}
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				vis[nx][ny] = 1;
				Q.push({ nx, ny });
			}
		}
	}
}