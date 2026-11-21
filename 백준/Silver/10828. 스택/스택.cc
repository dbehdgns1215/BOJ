#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	stack<int> stk;

	while (q--)
	{
		string func;
		cin >> func;
		
		if (func == "push")
		{
			int add;
			cin >> add;
			stk.push(add);
		}
		else if (func == "pop")
		{
			if (stk.empty())
			{
				cout << -1 << "\n";
			}
			else if (stk.empty() == false)
			{
				cout << stk.top() << "\n";
				stk.pop();
			}
		}
		else if (func == "size")
		{
			cout << stk.size() << "\n";
		}
		else if (func == "empty")
		{
			if (stk.empty())
			{
				cout << 1 << "\n";
			}
			else if (stk.empty() == false)
			{
				cout << 0 << "\n";
			}
		}
		else if (func == "top")
		{
			if (stk.empty())
			{
				cout << -1 << "\n";
			}
			else if (stk.empty() == false)
			{
				cout << stk.top() << "\n";
			}
		}
	}
}