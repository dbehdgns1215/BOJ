#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> heights(n);
    vector<int> result(n, 0); // 결과 배열, 초기값 0
    stack<pair<int, int>> s; // {높이, 인덱스} 저장하는 스택

    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && s.top().first <= heights[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top().second + 1; // 인덱스가 0부터 시작하므로 +1
        }
        s.push({heights[i], i});
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
}
