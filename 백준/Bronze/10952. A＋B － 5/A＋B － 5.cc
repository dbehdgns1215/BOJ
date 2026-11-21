#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	bool check = false;

	while (!check)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
		{
			break;
		}
		cout << a + b << "\n";
	}
}