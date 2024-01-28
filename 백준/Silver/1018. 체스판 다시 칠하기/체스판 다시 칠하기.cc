#include <bits/stdc++.h>
using namespace std;

int n, m;
char c[51][51];
int dx[2] = { 0, 1 }, dy[2] = { 1, 0 };

int check(int x, int y) {
    int cnt1 = 0, cnt2 = 0;
    char start1[2] = { 'W', 'B' }, start2[2] = { 'B', 'W' };
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (c[x + i][y + j] != start1[(i + j) % 2]) cnt1++;
            if (c[x + i][y + j] != start2[(i + j) % 2]) cnt2++;
        }
    }
    return min(cnt1, cnt2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            ans = min(ans, check(i, j));
        }
    }

    cout << ans;

    return 0;
}
