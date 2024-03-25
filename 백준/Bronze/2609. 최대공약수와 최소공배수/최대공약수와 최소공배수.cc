#include <bits/stdc++.h>
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

    int a, b;

    cin >> a >> b;

    cout << gcd(a, b) << "\n" << a * b / gcd(a, b);

}