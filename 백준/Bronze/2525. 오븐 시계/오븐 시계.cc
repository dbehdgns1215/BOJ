#include <bits/stdc++.h>
using namespace std;

int main() {
    int current_hour, current_minute, cooking_time;

    // 현재 시각 입력 받기
    cin >> current_hour >> current_minute;

    // 요리하는 데 필요한 시간 입력 받기
    cin >> cooking_time;

    // 요리가 끝나는 시각 계산하기
    int end_minute = (current_minute + cooking_time) % 60;
    int carry_hour = (current_minute + cooking_time) / 60;

    int end_hour = (current_hour + carry_hour) % 24;

    // 계산된 결과 출력하기
    cout << end_hour << " " << end_minute << endl;

    return 0;
}