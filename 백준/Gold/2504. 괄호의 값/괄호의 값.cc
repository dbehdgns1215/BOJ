#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    cin >> line;

    stack<char> stk;
    int temp = 1;
    int sum = 0;

    for (int i = 0; i < line.size(); i++) {
        char ch = line[i];

        if (ch == '(' || ch == '[') {
            stk.push(ch);
            temp *= (ch == '(') ? 2 : 3;
        } else if (ch == ')' || ch == ']') {
            if (stk.empty() || ((ch == ')' && stk.top() != '(') || (ch == ']' && stk.top() != '['))) {
                cout << 0 << "\n";
                return 0;
            }
            if (i > 0 && (line[i - 1] == '(' || line[i - 1] == '[')) {
                sum += temp;
            }
            temp /= (ch == ')') ? 2 : 3;
            stk.pop();
        } else {
            cout << 0 << "\n";
            return 0;
        }
    }

    if (stk.empty()) {
        cout << sum << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
