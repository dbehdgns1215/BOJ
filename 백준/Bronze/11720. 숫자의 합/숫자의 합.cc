#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	string k;
	int sum = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		sum += k[i] - 48;
	}

	cout << sum;

}