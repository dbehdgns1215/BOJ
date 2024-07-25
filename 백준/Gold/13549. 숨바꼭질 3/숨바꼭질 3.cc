#include <bits/stdc++.h>
using namespace std;

int n, k;
bool vis[100001];
int dist[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    deque<int> Q;
    Q.push_back(n);
    vis[n] = 1;
    dist[n] = 0;

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop_front();

        // 목표 위치에 도달한 경우
        if (cur == k) {
            cout << dist[cur];
            return 0;
        }

        // 순간이동 처리
        int nx = cur * 2;
        if (nx <= 100000 && !vis[nx]) {
            vis[nx] = 1;
            dist[nx] = dist[cur];
            Q.push_front(nx);  // 순간이동은 0초이므로 앞에 추가
        }

        // 걷는 경우 처리
        for (int dir : {-1, 1}) {
            nx = cur + dir;
            if (nx >= 0 && nx <= 100000 && !vis[nx]) {
                vis[nx] = 1;
                dist[nx] = dist[cur] + 1;
                Q.push_back(nx);  // 걷는 경우는 1초 걸리므로 뒤에 추가
            }
        }
    }
}
