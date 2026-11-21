#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[9], max;

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		if (i == 0)
		{
			max = arr[i];
		}
		else if ( i == 8)
		{
			if (max > arr[i])
			{
				break;
			}
			else
			{
				max = arr[i];
			}
		}
		else
		{
			if (max > arr[i])
			{
				continue;
			}
			else
			{
				max = arr[i];
			}
		}
	}

	cout << max << "\n";
	for (int j = 0; j < 9; j++)
	{
		if (max == arr[j])
		{
			cout << j+1;
		}
	}
}