#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		int num = i;

		while (num != 0) {
			sum += num % 10;
			num = num / 10;
		}
		// cout << i << " " << sum << "\n";   디버깅 용

		// sum + i 의 값 -> 분해합의 결과가 n이랑 같냐를 확인해야 했는데 여태까지 그냥 자릿수 합만 생각했음.
		if (n == (sum + i)) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}