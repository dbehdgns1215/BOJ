#include <bits/stdc++.h>
using namespace std;

// 유클리드 호제법 공식. gcd(a, b) = gcd(b, r) (단, a = q*b + r 라고 가정했을 때)
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    // 분수의 합 계산
    long long numerator = a1 * b2 + a2 * b1;
    long long denominator = b1 * b2;

    // 기약분수로 만들기
    long long g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;

    cout << numerator << ' ' << denominator;
}
