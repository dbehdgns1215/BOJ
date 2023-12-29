#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N;
	cin >> N;

	long long sum = 0;
	N--;
	while (N != 0)
	{
		sum += N;
		N--;
	}

	cout << sum << "\n2";
}