#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int nan[9];
	int height_sum = 0;


	for (int i = 0; i < 9; i++)
	{
		cin >> nan[i];
		height_sum += nan[i];
	}
	int fake_height = height_sum - 100;

	sort(nan, nan + 9);

	bool flag = false;

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (fake_height == nan[i] + nan[j])
			{
				nan[i] = 0;
				nan[j] = 0;
				flag = true;
				break;
			}
		}
		if (flag) { break; }
	}

	for (int i = 0; i < 9; i++)
	{
		if (nan[i] != 0)
		{
			cout << nan[i] << "\n";
		}
	}
}