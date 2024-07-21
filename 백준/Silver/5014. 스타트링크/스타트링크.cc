#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d;

int board[1000001];
int vis[1000001];
int dist[1000001];

bool is_find;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> f >> s >> g >> u >> d;
	
	if (s == g) {
		cout << "0";
		return 0;
	}

	for (int i = 0; i < f; i++)
	{
		board[i] = 1;
	}

	board[g] = -1;

	queue<int> Q;;

	vis[s] = 1;
	Q.push(s);

	int dx[2] = { u, -d };

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 2; dir++)
		{
			int nx = cur + dx[dir];

			if (nx < 1 || nx > f) continue;
			if (vis[nx] == 1) continue;
			if (board[nx] == -1) {
				cout << dist[cur] + 1;
				is_find = true;
				return 0;
			}
			dist[nx] = dist[cur] + 1;
			vis[nx] = 1;
			Q.push(nx);
		}
	}

	if (!is_find)
	{
		cout << "use the stairs";
	}

}