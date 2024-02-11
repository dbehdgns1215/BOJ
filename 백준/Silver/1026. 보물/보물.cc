#include <bits/stdc++.h>
using namespace std;

int a[101], b[101];
int n, sum;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	sort(a, a + n);
	sort(b, b + n, compare);

	for (int i = 0; i < n; i++)
	{
		sum += a[i] * b[i];
	}
	cout << sum;
}