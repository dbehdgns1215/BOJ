#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N; // 승환이 앞에 서 있는 학생들의 수 입력 받기
    stack<int> s;
    int current = 1;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num; // 번호표 순서대로 입력 받기
        s.push(num); // 입력 받은 번호표를 스택에 저장
        while (!s.empty() && s.top() == current) { // 스택이 비어있지 않고, 스택의 맨 위 번호표가 현재 순서와 일치하면
            s.pop(); // 스택에서 제거
            current++; // 다음 순서로 넘어감
        }
    }
    if (s.empty()) cout << "Nice";
    else cout << "Sad";
}
