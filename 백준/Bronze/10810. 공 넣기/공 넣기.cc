#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, i, j, k;
	int bucket[102] = {};
	
	cin >> n >> m;
	int h = n;

	for (int t=0; t < m; t++)
	{
		cin >> i >> j >> k;
		int f = j - i + 1;
		for (int l=0; l < f; l++)
		{
			bucket[i-1] = k;
			i++;
		}
	}
	
	for (int q=0; q < h; q++)
	{
		cout << bucket[q] << " ";
	}
}