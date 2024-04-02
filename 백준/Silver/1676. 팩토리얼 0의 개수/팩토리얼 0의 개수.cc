#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int count = 0;

    // N!에 포함된 5의 배수, 5^2의 배수, 5^3의 배수 등을 세어 0의 개수를 구합니다.
    for (int i = 5; N / i >= 1; i *= 5) {
        count += N / i;
    }

    cout << count;

    return 0;
}
