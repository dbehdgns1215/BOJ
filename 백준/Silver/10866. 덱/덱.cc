#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	deque<int> deq;

	while (q--)
	{
		string op;
		cin >> op;

		if (op == "push_front")
		{
			int add;
			cin >> add;

			deq.push_front(add);
		}
		else if (op == "push_back")
		{
			int add;
			cin >> add;

			deq.push_back(add);
		}
		else if (op == "pop_front")
		{
			if (deq.empty() != 1)
			{
				cout << deq.front() << "\n";
				deq.pop_front();
			}
			else cout << -1 << "\n";
		}
		else if (op == "pop_back")
		{
			if (deq.empty() != 1)
			{
				cout << deq.back() << "\n";
				deq.pop_back();
			}
			else cout << -1 << "\n";
		}
		else if (op == "size")
		{
			cout << deq.size() << "\n";
		}
		else if (op == "empty")
		{
			cout << deq.empty() << "\n";
		}
		else if (op == "front")
		{
			if (deq.empty() == 1) cout << -1 << "\n";
			else cout << deq.front() << "\n";
		}	
		else if (op == "back")
		{
			if (deq.empty() == 1) cout << -1 << "\n";
			else cout << deq.back() << "\n";
		}
	}
}

