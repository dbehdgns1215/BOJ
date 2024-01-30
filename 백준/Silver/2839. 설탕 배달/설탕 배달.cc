#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	while (n >= 0)
	{
		if (n % 5 == 0)
		{
			cnt += n / 5;
			n = n / 5;
			cout << cnt;
			return 0;
		}
		n -= 3;
		cnt++;
	}
	cout << -1;
	return 0;
}