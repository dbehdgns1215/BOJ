#include <bits/stdc++.h>
using namespace std;

int r, c;
char maze[1001][1001];
int fireTime[1001][1001];
int exitTime[1001][1001];
queue<pair<int, int>> jihoon;
queue<pair<int, int>> fire;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			fireTime[i][j] = -1;
			exitTime[i][j] = -1;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> maze[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (maze[i][j] == 'J') {
				jihoon.push({ i, j });
				exitTime[i][j] = 0;
			} else if (maze[i][j] == 'F') {
				fire.push({ i, j });
				fireTime[i][j] = 0;
			}
		}
	}

	// 불 BFS
	while (!fire.empty()) {
		auto cur = fire.front(); fire.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + cur.first;
			int ny = dy[dir] + cur.second;

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (maze[nx][ny] == '#') continue;
			if (fireTime[nx][ny] >= 0) continue;

			fireTime[nx][ny] = fireTime[cur.first][cur.second] + 1;
			fire.push({ nx, ny });
		}
	}

	// 지훈 BFS
	while (!jihoon.empty()) {
		auto cur = jihoon.front(); jihoon.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + cur.first;
			int ny = dy[dir] + cur.second;

			// 지훈이가 미로를 벗어나면 탈출 성공
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << exitTime[cur.first][cur.second] + 1;
				return 0;
			}

			if (maze[nx][ny] == '#') continue;
			if (exitTime[nx][ny] >= 0) continue;
			if (fireTime[nx][ny] != -1 && fireTime[nx][ny] <= exitTime[cur.first][cur.second] + 1) continue;

			exitTime[nx][ny] = exitTime[cur.first][cur.second] + 1;
			jihoon.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";
}