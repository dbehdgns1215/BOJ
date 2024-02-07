#include <bits/stdc++.h>
using namespace std;

pair <int, int> p[100001];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n);
	
	for (int i = 0; i < n; i++)
	{
		cout << p[i].first << " " << p[i].second << "\n";
	}
}