#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string series;

	cin >> n;

	for (int i = 665; i < INT_MAX; i++)
	{
		series = to_string(i);

		for (int j = 0; j < series.length(); j++)
		{
			if (series[j] == '6' && series[j + 1] == '6' && series[j + 2] == '6')
			{
				cnt++;
				break;
			}
		}
		if (cnt == n) { cout << i; return 0; }
	}
}