#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int determinant = a * e - b * d; // 행렬의 행렬식 (ad - bc)
    int x = (c * e - b * f) / determinant; // x 값 계산
    int y = (a * f - c * d) / determinant; // y 값 계산

    cout << x << " " << y;
}
