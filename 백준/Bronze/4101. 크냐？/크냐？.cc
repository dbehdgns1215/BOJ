#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a = -1, b = -1;

	while (a != 0 && b != 0)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
		{
			return 0;
		}
		if (a > b)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
}