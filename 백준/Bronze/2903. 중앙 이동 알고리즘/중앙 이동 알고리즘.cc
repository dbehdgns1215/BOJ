#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	int init = 1; // 원본
	int sum = 1; // 원본 증가량
	int result;

	// 원본	제곱	2^2   3^2   5^2   9^2   17^2   33^2
	// 원본          2     3     5     9     17     33
	// 원본 증가량     2^0   2^1   2^2   2^3    2^4
	
	// 원본을 2의 제곱수만큼 더하고 제곱한다는 위와 같은 반복 패턴을 가진다는 것을 알 수 있음.

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		sum *= 2;
	}
	
	result = (init + sum) * (init + sum);
	cout << result;
}