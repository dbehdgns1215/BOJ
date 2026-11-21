#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[102], n, v, cnt;
	cnt = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cin >> v;
	for (int j = 0; j < n; j++)
	{
		if (arr[j] == v) cnt++;
	}

	cout << cnt;
	



	
}