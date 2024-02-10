#include <bits/stdc++.h>
using namespace std;

pair <int, string> user[100001];
int n;

bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> user[i].first >> user[i].second;
	}

	stable_sort(user, user + n, compare);

	for (int i = 0; i < n; i++)
	{
		cout << user[i].first << " " << user[i].second << "\n";
	}
}