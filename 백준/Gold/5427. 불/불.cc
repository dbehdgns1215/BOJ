#include <bits/stdc++.h>
using namespace std;

int t, w, h;
char board[1001][1001];

int fire[1001][1001];
int sk[1001][1001];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool Find;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;

	queue<pair<int, int>> F;
	queue<pair<int, int>> SK;

	for (int i = 0; i < t; i++)
	{
		cin >> w >> h;

		Find = false;

		for (int j = 0; j < h; j++)
		{
			for (int k = 0; k < w; k++)
			{
				fire[j][k] = -1;
				sk[j][k] = -1;
			}
		}

		for (int j = 0; j < h; j++)
		{
			for (int k = 0; k < w; k++)
			{
				cin >> board[j][k];
				if (board[j][k] == '*')
				{
					F.push({ j, k });
					fire[j][k] = 0;
				}
				else if (board[j][k] == '@')
				{
					SK.push({ j, k });
					sk[j][k] = 0;
				}
			}
		}

		while (!F.empty())
		{
			auto cur = F.front(); F.pop();
			
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				fire[nx][ny] = fire[cur.first][cur.second] + 1;
				F.push({ nx, ny });
			}
		}

		while (!SK.empty())
		{
			auto cur = SK.front(); SK.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				{
					cout << sk[cur.first][cur.second] + 1 << "\n";
					Find = true;
					while (!SK.empty())
					{
						SK.pop(); 
					}
					break;
				}
				if (sk[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				// 기본적으로 [nx][ny]는 조건 검사가 끝나고 나서 업데이트 되는 것이기 때문에 sk[nx][ny]로 조건을 검사하면 안됨
				if (board[nx][ny] == '*' || (fire[nx][ny] != -1 && sk[cur.first][cur.second] + 1 >= fire[nx][ny])) continue;

				sk[nx][ny] = sk[cur.first][cur.second] + 1;
				SK.push({ nx, ny });
			}
		}
		if (Find == false) cout << "IMPOSSIBLE\n";
	}
}