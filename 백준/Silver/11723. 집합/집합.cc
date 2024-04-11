#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> m;

	int arr[21] = { 0 };

	while (m--)
	{
		string op;
		cin >> op;

		int x;

		if (op == "add")
		{
			cin >> x;
			arr[x] = 1;
		}
		else if (op == "remove")
		{
			cin >> x;
			if (arr[x] == 1)
			{
				arr[x] = 0;
			}
		}
		else if (op == "check")
		{
			cin >> x;
			if (arr[x] == 1)
			{
				cout << "1\n";
			}
			else { cout << "0\n"; }
		}
		else if (op == "toggle")
		{
			cin >> x;
			if (arr[x] == 1)
			{
				arr[x] = 0;
			}
			else { arr[x] = 1; }
		}
		else if (op == "all")
		{
			for (int i = 1; i <= 20; i++)
			{
				arr[i] = 1;
			}
		}
		else if (op == "empty")
		{
			for (int i = 1; i <= 20; i++)
			{
				arr[i] = 0;
			}
		}
	}
}