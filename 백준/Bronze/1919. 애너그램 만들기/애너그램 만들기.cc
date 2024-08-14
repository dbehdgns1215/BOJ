#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2;
    cin >> str1 >> str2;

    map<char, int> m1, m2;

    // 첫 번째 문자열의 문자 빈도 계산
    for (char c : str1) {
        m1[c]++;
    }

    // 두 번째 문자열의 문자 빈도 계산
    for (char c : str2) {
        m2[c]++;
    }

    int result = 0;

    // 두 문자 빈도 맵을 비교하여 차이 계산
    for (auto& pair : m1) {
        char c = pair.first;
        int count1 = pair.second;
        int count2 = m2[c]; // 두 번째 문자열에서의 문자 빈도

        // 빈도 차이만큼 제거해야 함
        result += abs(count1 - count2);
    }

    // 두 번째 문자열에서 첫 번째 문자열에 없는 문자 처리
    for (auto& pair : m2) {
        char c = pair.first;
        if (m1.find(c) == m1.end()) {
            result += pair.second;
        }
    }

    cout << result;
}
