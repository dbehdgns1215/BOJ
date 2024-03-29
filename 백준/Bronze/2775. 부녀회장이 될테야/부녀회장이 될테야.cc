#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, k, n;
    cin >> T; // 테스트 케이스의 수 T를 입력받음

    for (int i = 0; i < T; i++) {
        cin >> k; // 층
        cin >> n; // 호

        int apartment[15][15] = { 0, }; // 아파트의 층과 호를 나타내는 2차원 배열 초기화

        // 0층의 i호에는 i명이 산다는 규칙에 따라 값을 설정
        for (int j = 1; j <= n; j++) {
            apartment[0][j] = j;
        }

        // 1층부터 k층까지, 각 층의 1호부터 n호까지 사람 수를 계산
        for (int floor = 1; floor <= k; floor++) {
            for (int room = 1; room <= n; room++) {
                // 현재 층의 이전 호수까지의 사람 수의 합을 현재 호수에 더함
                apartment[floor][room] = apartment[floor][room - 1] + apartment[floor - 1][room];
            }
        }

        // k층 n호에 사는 사람 수를 출력
        cout << apartment[k][n] << "\n";
    }
}
