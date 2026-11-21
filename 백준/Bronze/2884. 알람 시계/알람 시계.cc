#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, m;
	
	cin >> h >> m;

	// 10 50
	// 10 5
	if (m - 45 < 0)
	{
		m = m - 45;
		h--;
		if (h < 0) h = h + 24;
		m = m + 60;
	}
	else m = m - 45;

	cout << h << " " << m;
}