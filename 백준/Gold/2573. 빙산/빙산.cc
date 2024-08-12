#include <bits/stdc++.h>
using namespace std;

int board[301][301];
bool visited[301][301];
int n, m;
queue<pair<int, int>> q; // 빙산 BFS용
queue<pair<int, int>> q2; // 빙산 덩이 체크용
int melt_year;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
}

int count_parts() {
    int parts = 0;
    reset();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] > 0 && !visited[i][j]) {
                parts++;
                q2.push({ i, j });
                visited[i][j] = true;

                while (!q2.empty()) {
                    auto cur = q2.front(); q2.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (visited[nx][ny] || board[nx][ny] == 0) continue;

                        q2.push({ nx, ny });
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }
    reset();
    return parts;
}

void bfs() {
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny] || board[nx][ny] == 0) continue;

            if (board[nx][ny] > 0) {
                board[nx][ny]--;

            }
        }
    }
    melt_year++;
    reset();
}

bool is_all_melted() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] > 0) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while (true) {
        int parts = count_parts();

        if (parts >= 2) {
            cout << melt_year;
            break;
        }
        if (is_all_melted()) {
            cout << 0;
            break;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0 && !visited[i][j]) {
                    q.push({ i, j });
                    visited[i][j] = true;
                }
            }
        }

        bfs();
    }
}