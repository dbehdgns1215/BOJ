#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a, b;

	while (1)
	{
		cin >> a >> b;

		if (a == 0 && b == 0)
		{
			break;
		}

		if (b != 0 && a % b == a && a!=0)
		{
			cout << "factor\n";
		}
		else if (b != 0 && a % b == 0 && a != 0)
		{
			cout << "multiple\n";
		}
		else
		{
			cout << "neither\n";
		}
	}
}