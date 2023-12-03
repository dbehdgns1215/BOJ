#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int B, N;

	cin >> N >> B;

	string result = "";

	while (N > 0)
	{
		int temp = N % B;
		if (temp < 10)
		{
			result += (char)('0' + temp);
		}
		else
		{
			result += (char)('A' - 10 + temp);
		}

		N = N / B;
	}

	reverse(result.begin(), result.end());
	cout << result;
}