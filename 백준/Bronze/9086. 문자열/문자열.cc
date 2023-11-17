#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;

	char test[1001];

	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> test;

		cout << test[0] << test[strlen(test) - 1] << "\n";
	}
}