#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, A[10002], x;

	cin >> t >> x;
	for (int i = 0; i < t; i++)
	{
		cin >> A[i];
	}

	for (int j = 0; j < t; j++)
	{
		if (A[j] < x) cout << A[j] << " ";
	}
}