#include <bits/stdc++.h>
using namespace std;

int n, m;
queue <int> A;
queue <int> B;
queue <int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		A.push(temp);
	}

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		B.push(temp);
	}

	while (!A.empty() && !B.empty())
	{
		auto a = A.front();
		auto b = B.front();

		if (a < b) {
			ans.push(a);
			A.pop();
		}
		else {
			ans.push(b);
			B.pop();
		}
	}

	if (A.empty() && !B.empty())
	{
		while (!B.empty())
		{
			auto temp = B.front();
			B.pop();
			ans.push(temp);
		}
	}
	else if (B.empty() && !A.empty())
	{
		while (!A.empty())
		{
			auto temp = A.front();
			A.pop();
			ans.push(temp);
		}
	}

	for (int i = 0; i < n + m; i++)
	{
		cout << ans.front() << " ";
		ans.pop();
	}
}