#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	bool paper[100][100] = { false };

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		for (int r = x; r < x + 10; r++) {
			for (int c = y; c < y + 10; c++) {
				paper[r][c] = true;
			}
		}
	}

	int circumference = 0;
	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j]) {
				for (int d = 0; d < 4; d++) {
					int ni = i + dx[d];
					int nj = j + dy[d];
					if (ni < 0 || ni >= 100 || nj < 0 || nj >= 100 || !paper[ni][nj]) {
						circumference++;
					}
				}
			}
		}
	}
	cout << circumference;
}