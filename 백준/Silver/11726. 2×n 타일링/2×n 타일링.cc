#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 점화식
	// D[i] = D[n-1] + D[n-2]
	// 좌측 최상단 칸을 기준으로
	// 세로 타일이 오느냐 가로 타일이 오느냐의 경우
	// 총 2가지로 나뉘고 각각의 경우의 수가 발생

	int D[1002];
	int n;

	cin >> n;

	D[0] = 0;
	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		D[i] = (D[i - 1] + D[i - 2]) % 10007;
	}
	cout << D[n];

	/*
	모듈러 연산의 성질

1. (A + B) % M = (A % M + B % M) % M

2. (A * B) % M = (A % M * B % M) % M
	*/
}