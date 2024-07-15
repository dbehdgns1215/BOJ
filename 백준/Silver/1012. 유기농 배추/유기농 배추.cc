#include <bits/stdc++.h>
using namespace std;

int board[2501][2501];
int vis[2501][2501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int t, m, n, k, cnt;

void reset() {
	for (int i = 0; i < 2501; ++i) {
		for (int j = 0; j < 2501; ++j) {
			board[i][j] = 0;
			vis[i][j] = 0;
		}
	}
	cnt = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	queue <pair<int, int>> Q;

	cin >> t;


	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> k; // m : 가로길이 , n : 세로길이, k : 배추의 개수

		reset(); 

		for (int j = 0; j < k; j++)
		{
			int x, y; 
			cin >> x >> y;
			board[y][x] = 1; // x, y 좌표지만 배열에서는 둘이 순서가 바뀜 board의 y자리가 세로길이, x자리가 가로길이임.
		}

		for (int o = 0; o < n; o++) // board 배열 순회하면서 배추가 있는 부분 확인
		{
			for (int k = 0; k < m; k++)
			{
				if (board[o][k] == 1 && !vis[o][k]) // 배추가 이미 있고 방문하지 않았다면 아래 코드 실행. 만약 vis가 1이라면
					// 해당 배추는 연결되어있는 다른 배추에 의해 이미 검사되었기 때문에 통과 (흰지렁이개수를 올리면 안됨.) 
				{
					Q.push({ o, k }); // BFS 시작
					vis[o][k] = 1;
					while (!Q.empty())
					{
						auto cur = Q.front(); Q.pop();

						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];

							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (vis[nx][ny] || board[nx][ny] != 1) continue;
							Q.push({ nx, ny });
							vis[nx][ny] = 1;
						}
					}
					cnt++; // BFS를 한 번 실행하고나면 발견한 배추와 연결된 모든 배추들을 확인했으니 배추흰지렁이 +1 그 후 다시 다음 배추 찾음.
				}
			}
		}
		cout << cnt << "\n"; // 배추흰지렁이 개수 출력. 
	}
}