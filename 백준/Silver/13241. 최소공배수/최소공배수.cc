#include <iostream>
using namespace std;

// 유클리트 호제법 공식. gcd(a, b) = gcd(b, r) (단, a = q*b + r 라고 가정했을 때)
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

    long long a, b;
    cin >> a >> b;

    // greatest common divisor
    long long g = gcd(a, b);
    // least common multiple -> 주어진 두 수를 곱하고 최대공약수로 나누면 나옴.
    long long lcm = a * b / g;

    cout << lcm << endl;

    return 0;
}
