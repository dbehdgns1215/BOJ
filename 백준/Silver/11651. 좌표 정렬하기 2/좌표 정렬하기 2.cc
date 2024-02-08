#include <bits/stdc++.h>
using namespace std;

int n;
pair <int, int> p[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p[i].second >> p[i].first;
	}

	sort(p, p + n);

	for (int i = 0; i < n; i++)
	{
		cout << p[i].second << " " << p[i].first << "\n";
	}
}