#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int target[10] = {};
	int ret[10] = {};
	int count = 0;
	int result[42] = {};

	for (int i = 0; i < 10; i++)
	{
		cin >> target[i];
	}

	for (int k = 0; k < 10; k++)
	{
		ret[k] = target[k] % 42;
		result[ret[k]] = 1;
	}

	for (int l = 0; l < 42; l++)
	{
		if (result[l] > 0)
		{
			count++;
		}
	}

	cout << count;
}