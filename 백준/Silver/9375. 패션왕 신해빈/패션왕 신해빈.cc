#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; // 테스트 케이스의 수
    cin >> t;

    while (t--) {
        int n; // 해빈이가 가진 의상의 수
        cin >> n;

        map<string, int> clothes; // 의상의 종류와 해당 종류의 의상 수를 저장하는 맵
        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type; // 의상의 이름과 종류를 입력받음

            // 해당 종류의 의상 수를 1 증가시킴. 존재하지 않는 경우 자동으로 0에서 시작
            clothes[type]++;
        }

        int result = 1; // 결과값을 계산하는데 사용. 아무것도 선택하지 않는 경우를 제외하기 위해 1로 초기화
        for (auto& cloth : clothes) {
            result *= (cloth.second + 1); // 각 종류의 의상 수에 안 입는 경우를 더한 후 결과값에 곱함
        }

        cout << result - 1 << '\n'; // 모두 안 입는 경우를 제외하고 출력
    }
}
