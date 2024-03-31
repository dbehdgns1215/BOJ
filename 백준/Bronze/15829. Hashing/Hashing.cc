#include <bits/stdc++.h>
using namespace std;

int L;
string s;

// long long -> 64비트 -(2^63)) ~ (2^63 - 1) ; -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807
// 부호비트로 1비트를 사용하기에 63승까지

// unsigned long long -> 64비트 0 ~ (2^64 - 1) ; 대략 18,446,744,073,709,551,615
// 분배법칙 = (A + B) mod M = A mod M + B mod M
// 덧셈, 뺄셈, 곱셈에 적용 됨.

unsigned long long r = 1;
unsigned long long ans;
static unsigned long long m = 1234567891;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L;
	cin >> s;

	for (int i = 0; i < L; i++)
	{
		ans = (ans + (s[i] - 'a' + 1) * r) % m; // 문자열의 각 문자에 대해 계산하고, 바로 모듈로 연산을 수행합니다.
		r = (r * 31) % m; // r을 갱신할 때도 모듈로 연산을 수행하여 오버플로우를 방지합니다.
	}
	cout << ans % m;
}