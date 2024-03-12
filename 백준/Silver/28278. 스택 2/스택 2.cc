#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int command;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input = 0;
		cin >> command;

		if (command == 1)
		{
			cin >> input;
			v.push_back(input);
		}
		else if (command == 2)
		{
			if (!v.empty())
			{
				cout << v.back() << "\n";
				v.pop_back();
			}
			else cout << "-1\n";
		}
		else if (command == 3)
		{
			cout << v.size() << "\n";
		}
		else if (command == 4)
		{
			if (v.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (command == 5)
		{
			if (v.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << v.back() << "\n";
			}
		}
	}
}