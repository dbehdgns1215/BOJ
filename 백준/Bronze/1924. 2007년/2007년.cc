#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력 받기
    int x, y;
    cin >> x >> y;

    // 날짜 계산
    struct tm date = {0};
    date.tm_year = 2007 - 1900;  // 연도는 1900을 뺀 값으로 설정
    date.tm_mon = x - 1;         // 월은 0부터 시작하므로 1을 빼줌
    date.tm_mday = y;            // 일

    mktime(&date);  // 날짜 계산

    // 요일 출력
    switch (date.tm_wday) {
        case 0:
            cout << "SUN\n";
            break;
        case 1:
            cout << "MON\n";
            break;
        case 2:
            cout << "TUE\n";
            break;
        case 3:
            cout << "WED\n";
            break;
        case 4:
            cout << "THU\n";
            break;
        case 5:
            cout << "FRI\n";
            break;
        case 6:
            cout << "SAT\n";
            break;
    }

    return 0;
}
