#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, a, b;


	cin >> t;
	int result[1002];

	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		result[i] = a + b;
	}

	for (int j = 0; j < t; j++)
	{
		cout << result[j] << endl;
	}
}