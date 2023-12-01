#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int board[100][100] = { -1 };
	int cnt;
	int size = 0;

	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		int x, y;
		cin >> x >> y;
		
		for (int j = x; j < x + 10; j++)
		{
			for (int k = y; k < y + 10; k++)
			{
				if (x > 100 || y > 100 || x < 0 || y < 0)
				{
					continue;
				}
				if (board[j][k] == 1) { continue; }
				board[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int k = 0; k < 100; k++)
		{
			if (board[i][k] == 1) {
				size++;
			}
			
		}
	}

	cout << size;
}