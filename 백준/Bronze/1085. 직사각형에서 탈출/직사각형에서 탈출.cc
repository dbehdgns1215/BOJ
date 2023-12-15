#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int min_x;
	int min_y;
	int min_dis;

	if (x < w - x)
	{
		min_x = x;
	}
	else { min_x = w - x; }

	if (y < h - y)
	{
		min_y = y;
	}
	else { min_y = h - y; }

	if (min_x < min_y)
	{
		min_dis = min_x;
	}
	else { min_dis = min_y; }

	cout << min_dis;
}