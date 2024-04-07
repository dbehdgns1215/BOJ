#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, b;
    cin >> n >> m >> b;

    int arr[501][501];

    // 땅의 높이 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int min_total_time = INT_MAX; // 최소 시간
    int max_height = 0; // 땅의 최대 높이

    // 블록의 높이를 0부터 256까지 시도
    for (int h = 0; h <= 256; h++) {
        int time = 0; // 현재 시도 중인 블록 높이일 때의 총 걸리는 시간
        int blocks = b; // 현재 인벤토리에 있는 블록 개수

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int diff = arr[i][j] - h;

                if (diff > 0) {
                    time += diff * 2; // 제거할 블록
                    blocks += diff; // 인벤토리에 추가
                }
                else {
                    time += -diff; // 추가할 블록
                    blocks -= -diff; // 인벤토리에서 빼기
                }
            }
        }

        // 인벤토리에 블럭이 최소 0개 있어야 가능한 방법이니까 이때만 계산.
        if (blocks >= 0) {
            // 최소 시간 갱신
            if (min_total_time >= time) {
                min_total_time = time;
                max_height = h;
            }
        }
    }

    cout << min_total_time << " " << max_height;
}
