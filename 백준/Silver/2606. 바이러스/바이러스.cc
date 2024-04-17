#include <bits/stdc++.h>
using namespace std;

vector<int> net[101]; // 각 컴퓨터에 연결된 컴퓨터 목록을 저장
bool zom[101]; // 각 컴퓨터의 방문(감염) 여부를 체크

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    for (int i = 0; i < t; i++) {
        int u, v;
        cin >> u >> v;
        net[u].push_back(v); // u 컴퓨터와 v 컴퓨터가 연결됨
        net[v].push_back(u); // v 컴퓨터와 u 컴퓨터가 연결됨 (양방향)
    }

    queue<int> q;
    q.push(1); // 1번 컴퓨터에서 시작
    zom[1] = true; // 1번 컴퓨터는 방문(감염) 처리
    int cnt = 0; // 감염된 컴퓨터 수

    while (!q.empty()) {
        int current = q.front(); q.pop();
        for (int next : net[current]) {
            if (!zom[next]) { // 아직 감염되지 않은 컴퓨터라면
                zom[next] = true; // 감염 처리
                q.push(next); // 큐에 추가
                cnt++;
            }
        }
    }

    cout << cnt;
}

