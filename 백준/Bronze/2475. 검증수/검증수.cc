#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int serial[5];

	for (int i = 0; i < 5; i++)
	{
		cin >> serial[i];
	}

	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += serial[i] * serial[i];
	}

	cout << sum % 10;
}