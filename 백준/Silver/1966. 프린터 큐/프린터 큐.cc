#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;

    while (T--) {
        int N, M; // N은 문서의 개수, M은 궁금한 문서의 위치
        cin >> N >> M;

        queue<pair<int, int>> q; // 첫 번째 인자는 문서의 중요도, 두 번째 인자는 위치
        priority_queue<int> pq; // 문서의 중요도를 내림차순으로 정렬

        for (int i = 0; i < N; ++i) {
            int importance;
            cin >> importance;
            q.push({ importance, i });
            pq.push(importance);
        }

        int count = 0; // 인쇄된 문서의 수
        while (!q.empty()) {
            int current_importance = q.front().first;
            int current_index = q.front().second;
            q.pop();

            if (current_importance == pq.top()) { // 현재 문서가 가장 중요도가 높은 문서라면
                ++count;
                pq.pop();
                if (current_index == M) { // 궁금한 문서가 인쇄되었다면
                    cout << count << '\n';
                    break;
                }
            }
            else {
                q.push({ current_importance, current_index }); // 뒤로 재배치
            }
        }
    }
}
