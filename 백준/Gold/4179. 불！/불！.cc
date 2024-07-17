#include <bits/stdc++.h>
using namespace std;

char board[1001][1001];
int fire[1001][1001];
int jihoon[1001][1001];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int r, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c;

	queue <pair<int, int>> F;
	queue <pair<int, int>> J;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			fire[i][j] = -1;
			jihoon[i][j] = -1;
			if (board[i][j] == 'F') {
				F.push({ i, j });
				fire[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				J.push({ i, j });
				jihoon[i][j] = 0;
			}
		}
	}

	// 불에 대한 BFS를 먼저 실행한 뒤 불이 퍼지는 시간 저장
	while (!F.empty())
	{
		auto cur = F.front(); F.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
						
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;

			fire[nx][ny] = fire[cur.first][cur.second] + 1;

			F.push({ nx, ny });
		}
	}

	// 지훈이에 대한 BFS를 실행하고 불의 확산 시간보다 일찍 이동이 가능한 경우에서 가장 빨리 탈출하는 시간 찾기
	while (!J.empty())
	{
		auto cur = J.front(); J.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			// 지훈이가 끝에 도달한 경우 '탈출'
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			{
				cout << jihoon[cur.first][cur.second] + 1;
				return 0;
			}

			// 지훈이가 이미 이동한 곳, 벽으로 이동, 지훈이가 불 보다 느리게 이동하는 곳(불난 곳 방문)의 경우는 제외 
			/*if (jihoon[nx][ny] >= 0 || board[nx][ny] == '#' || jihoon[nx][ny] >= fire[nx][ny])
			{
				continue;
			}
			*/ // 이 코드가 안되는 이유는 jihoon[nx][ny]가 아직 업데이트 되지 않았기 때문에 -1일 수도 있음.

			if (jihoon[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (fire[nx][ny] != -1 && jihoon[cur.first][cur.second] + 1 >= fire[nx][ny])
			{
				continue;
			}
						
			jihoon[nx][ny] = jihoon[cur.first][cur.second] + 1;
			J.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";
}