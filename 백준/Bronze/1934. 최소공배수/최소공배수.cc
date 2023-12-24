#include <bits/stdc++.h>
using namespace std;

// 최대공약수를 구하는 함수
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 최소공배수를 구하는 함수
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        // 최소공배수 출력
        cout << lcm(A, B) << "\n";
    }

}
