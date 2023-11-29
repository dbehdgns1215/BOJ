#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A[9][9];

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> A[i][j];
		}
	}

	int max = 0;
	int m, n;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (max <= A[i][j])
			{
				max = A[i][j];
				m = i;
				n = j;
			}

		}
	}
	
	cout << max << "\n";
	cout << m + 1 << " " << n + 1;
	
}