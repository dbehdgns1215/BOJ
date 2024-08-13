#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    queue<int> q;
    vector<int> result;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    // 요세푸스 순열을 계산
    while (!q.empty()) {
        // K-1번 앞에서 빼서 뒤로 보냄
        for (int i = 0; i < K - 1; i++) {
            int cur = q.front();
            q.pop();
            q.push(cur);
        }

        // K번째 사람을 제거하여 결과에 추가
        result.push_back(q.front());
        q.pop();
    }

    // 결과 출력
    cout << "<";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">";

}
