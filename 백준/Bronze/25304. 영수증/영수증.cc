#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int total, n, a, b;
	int check = 0;

	cin >> total;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		check += a * b;
	}

	if (check == total)
	{
		cout << "Yes";
	}
	else cout << "No";
}