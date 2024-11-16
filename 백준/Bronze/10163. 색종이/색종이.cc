#include <bits/stdc++.h>
using namespace std;

int paper[1001][1001];
int cnt[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, y1, width, height;
		cin >> x1 >> y1 >> width >> height;
		int x2 = x1 + width;
		int y2 = y1 + height;

		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				paper[j][k] = i + 1;
			}
		}
	}

	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			cnt[paper[i][j]]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << cnt[i] << "\n";
	}
}
