#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> s; // 스택 선언
    vector<char> operations; // 연산을 저장할 벡터
    int current = 1; // 현재 push해야 하는 숫자
    bool possible = true; // 수열을 만들 수 있는지 여부

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        // 현재 숫자를 스택에 push
        while (current <= num) {
            s.push(current++);
            operations.push_back('+');
        }

        // 스택의 top이 현재 숫자와 같다면 pop
        if (s.top() == num) {
            s.pop();
            operations.push_back('-');
        }
        else {
            // 만들 수 없는 경우
            possible = false;
        }
    }

    if (possible) {
        for (char op : operations) {
            cout << op << '\n';
        }
    }
    else {
        cout << "NO" << '\n';
    }
}
