#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;

	cin >> N;

	for (int i = 0; i < 9; i++)
	{
		cout << N << " * " << i + 1 << " = " << N * (i + 1) << endl;
	}
}