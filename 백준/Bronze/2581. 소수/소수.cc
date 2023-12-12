#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, N;

	cin >> M;
	cin >> N;

	int sum = 0;

	int min = -1;



	for (int i = M; i <= N; i++)
	{
		if (i == 1) { continue; }
		bool prime = true;
		for (int k = 2; k < i; k++)
		{
			if (i % k == 0)
			{
				prime = false;
				break; // 소수가 아님
			}
		}
		if (prime == true)
		{
			sum += i;
			if (min == -1)
			{
				min = i;
			}
		}
	}

	if (sum == 0) { cout << -1; return 0; }
	cout << sum << endl;
	cout << min;
}
