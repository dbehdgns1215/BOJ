#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int line[3];

    while (1) {
        cin >> line[0] >> line[1] >> line[2];

        // 종료 구문
        if (line[0] == 0 && line[1] == 0 && line[2] == 0) {
            return 0;
        }

        // Invalid 출력
        sort(line, line + 3);

        if (line[0] + line[1] <= line[2]) {
            cout << "Invalid\n";
            continue;
        }

        // 길이에 따른 출력문
        if (line[0] == line[1] && line[0] == line[2]) {
            cout << "Equilateral\n";
        } else if (line[0] == line[1] || line[1] == line[2]) {
            cout << "Isosceles\n";
        } else {
            cout << "Scalene\n";
        }
    }
}
