#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> st;   // 빌딩 높이를 저장할 스택
    long long cnt = 0; // 관리인들이 볼 수 있는 빌딩 수의 합

    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;

        // 스택에서 현재 빌딩보다 낮거나 같은 빌딩 제거
        while (!st.empty() && st.top() <= height) {
            st.pop();
        }

        // 스택에 남아있는 빌딩의 수가 현재 빌딩에서 볼 수 있는 빌딩의 수
        cnt += st.size();

        // 현재 빌딩을 스택에 추가
        st.push(height);
    }

    cout << cnt << "\n";

}
