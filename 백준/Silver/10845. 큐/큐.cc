#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	queue<int> que;

	while (q--)
	{
		string op;
		cin >> op;

		if (op == "push")
		{
			int add;
			cin >> add;

			que.push(add);
		}
		else if (op == "pop")
		{
			if (que.empty() != 1)
			{
				cout << que.front() << "\n";
				que.pop();
			}
			else cout << -1 << "\n";
		}
		else if (op == "size")
		{
			cout << que.size() << "\n";
		}
		else if (op == "empty")
		{
			cout << que.empty() << "\n";
		}
		else if (op == "front")
		{
			if (que.empty() == 1) cout << -1 << "\n";
			else cout << que.front() << "\n";
		}
		else if (op == "back")
		{
			if (que.empty() == 1) cout << -1 << "\n";
			else cout << que.back() << "\n";
		}
	}
}

