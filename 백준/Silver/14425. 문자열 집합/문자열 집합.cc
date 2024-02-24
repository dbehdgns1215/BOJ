#include <bits/stdc++.h>
using namespace std;

vector <string> v;
int n;
int m;
int cnt;
string temp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		if (binary_search(v.begin(), v.end(), temp))
		{
			cnt++;
		}
	}
	cout << cnt;
}