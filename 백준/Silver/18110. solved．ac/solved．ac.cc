#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	if (n == 0) { cout << "0"; return 0; }
	float avg;

	vector <int> v;

	for (int i = 0; i < n; i++)
	{
		int level;
		cin >> level;
		v.push_back(level);
	}
	sort(v.begin(), v.end());
	avg = (float)n * 0.15;
	avg += 0.5;

	int n2;
	n2 = (int)avg;

	float level = 0;
	for (int i = n2; i < n - n2; i++)
	{
		level += v[i];
	}
	cout << (int)((level / (n - (n2 * 2))) + 0.5);


}