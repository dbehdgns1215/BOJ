#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	int bucket[102] = {};
	int transfer[102] = {};
	int i, j;
	int temp;

	cin >> n >> m;

	for (int f = 0; f < n; f++)
	{
		bucket[f] = f + 1;
		transfer[f] = f + 1;
	}

	for (int g = 0; g < m; g++)
	{
		cin >> i >> j;

		// b 2 1 4 3 5
		// t 2 1 4 3 5

		temp = bucket[i - 1];
		for (int a = 0; a < j - i; a++)
		{
			transfer[i - 1 + a] = bucket[j - 1 - a];
		}
		transfer[j - 1] = temp;

		for (int b = 0; b < n; b++)
		{
			bucket[b] = transfer[b];
		}
	}

	for (int l = 0; l < n; l++)
	{
		cout << bucket[l] << " ";
	}
}