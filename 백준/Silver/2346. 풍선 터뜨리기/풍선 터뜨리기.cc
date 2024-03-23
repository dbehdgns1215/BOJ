#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	deque <pair<int, int>> dq;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int ans;
		cin >> ans;
		// ans -> 풍선의 적힌 수, i -> 풍선의 번호
		dq.push_back(make_pair(i, ans));
	}

	int step = dq.front().second;
	cout << dq.front().first + 1 << " ";
	dq.pop_front();

	while (!dq.empty())
	{
		if (step > 0)
		{
			for (int k = 0; k < step - 1; k++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			cout << dq.front().first + 1 << " ";
			step = dq.front().second;
			dq.pop_front();
		}
		else if (step < 0)
		{
			step = abs(step);
			for (int k = 0; k < step; k++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cout << dq.front().first + 1 << " ";
			step = dq.front().second;
			dq.pop_front();
		}
	}
}