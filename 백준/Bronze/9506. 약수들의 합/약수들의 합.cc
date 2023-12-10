#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	while (1)
	{
		int sum = 0;
		string str = "";

		cin >> n;

		if (n == -1) { break; }

		for (int i = 1; i < n; i++)
		{
			if (n % i == 0)
			{
				sum += i;
				str += to_string(i) + " + ";
			}
		}
		if (n == sum)
		{
			str = str.substr(0, str.length() - 3);
			cout << n << " = " << str << "\n";
		}
		else { cout << n << " is NOT perfect.\n"; }
	}
}

