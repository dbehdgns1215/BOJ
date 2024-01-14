#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c) {
	// 기저조건
	if (n == 0) return 0;

	// 사분면의 절반. 비트 연산자 주목 1 << n 은 결국 2^n을 표현하는 방법.
	int half = 1 << (n - 1);

	// 왼쪽 위 사분면
	if (half > r && half > c) return func(n - 1, r, c);

	// 오른쪽 위 사분면
	if (half > r && half <= c) return half * half +func(n - 1, r, c - half);

	// 왼쪽 아래 사분면
	if (half <= r && half > c) return half * half * 2 + func(n - 1, r - half, c);

	// 오른쪽 아래 사분면
	return half * half * 3 + func(n - 1, r - half, c - half);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}