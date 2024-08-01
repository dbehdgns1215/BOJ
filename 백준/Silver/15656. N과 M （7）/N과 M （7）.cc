#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
vector <int> v;

void func(int k) {
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n"; 
		return;
	}

	for (int i = 0; i < n; i++)
	{
		arr[k] = v[i];
		func(k + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	func(0);
}