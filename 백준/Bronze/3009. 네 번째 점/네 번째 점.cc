#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x[1000], y[1000];
	int _x, _y;

	for (int i = 0; i < 3; i++)
	{
		cin >> x[i] >> y[i];
	}
	if (x[0] == x[1])
	{
		_x = x[2];
	}
	else if (x[0] == x[2])
	{
		_x = x[1];
	}
	else
	{
		_x = x[0];
	}

	if (y[0] == y[1])
	{
		_y = y[2];
	}
	else if (y[0] == y[2])
	{
		_y = y[1];
	}
	else
	{
		_y = y[0];
	}

	cout << _x << " " << _y;
}