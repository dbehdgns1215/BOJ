#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n >> k;

    queue<int> q;

    // 1부터 N까지의 숫자를 큐에 삽입
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << "<";
    while (!q.empty()) {
        // K-1번째 사람까지는 큐의 뒤로 보내고, K번째 사람을 제거
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        // K번째 사람 출력
        cout << q.front();
        q.pop();

        if (!q.empty()) {
            cout << ", ";
        }
    }
    cout << ">";
}