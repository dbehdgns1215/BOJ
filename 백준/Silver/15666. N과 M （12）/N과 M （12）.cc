#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> nums;
vector <int> sequence;

void func(int k, int start) {
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << sequence[i] << " ";
		}
		cout << "\n";
		return;
	}

	int last = 0;
	for (int i = start; i < n; i++)
	{
		if (nums[i] != last)
		{
			sequence.push_back(nums[i]);
			func(k + 1, i);
			sequence.pop_back();
			last = nums[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		nums.push_back(temp);
	}

	sort(nums.begin(), nums.end());
	func(0, 0);
}