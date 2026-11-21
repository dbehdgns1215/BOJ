#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	int min = 1000000;
	int max = -1000000;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int num;
		cin >> num;
		if (num >= max) max = num;

		if (num <= min) min = num;
	}
	
	cout << min << " " << max;
}