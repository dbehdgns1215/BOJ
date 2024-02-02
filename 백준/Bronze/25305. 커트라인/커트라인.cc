#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cout << arr[n - k];
}