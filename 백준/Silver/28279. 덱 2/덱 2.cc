#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	deque<int> dq;
	for (int i = 0; i < N; ++i) {
		int op;
		cin >> op;

		if (op == 1) {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (op == 2) {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (op == 3) {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (op == 4) {
			if (!dq.empty()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (op == 5) {
			cout << dq.size() << "\n";
		}
		else if (op == 6) {
			cout << (dq.empty() ? 1 : 0) << "\n";
		}
		else if (op == 7) {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		else if (op == 8) {
			if (!dq.empty()) {
				cout << dq.back() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}
}


/*
#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	queue <int> q;

	while (n--)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			if (q.empty())
			{
				int x;
				cin >> x;
				q.push(x);
			}
			else
			{
				int x;
				cin >> x;
				q.push(x);
				int size = q.size();
				for (int i = 0; i < size - 1; i++) {
					q.push(q.front());
					q.pop();
				}
			}
		}
		else if (op == 2)
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (op == 3)
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else { cout << "-1\n"; }
		}
		else if (op == 4)
		{
			if (!q.empty())
			{
				int size = q.size();
				cout << q.back() << "\n";
				for (int i = 0; i < size - 1; i++) {
					q.push(q.front());
					q.pop();
				}
			}
			else { cout << "-1\n"; }
		}
		else if (op == 5)
		{
			cout << q.size() << "\n";
		}
		else if (op == 6)
		{
			if (q.empty())
			{
				cout << "1\n";
			}
			else cout << "0\n";
		}
		else if (op == 7)
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
			}
			else cout << "-1\n";
		}
		else
		{
			if (!q.empty())
			{
				cout << q.back() << "\n";
			}
			else cout << "-1\n";
		}
	}
}
*/
