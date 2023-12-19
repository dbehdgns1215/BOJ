#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;

	int bead_x[100000];
	int bead_y[100000];

	int max_x = 20002;
	int min_x = -20002;

	int max_y = 20002;
	int min_y = -20002;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> bead_x[i] >> bead_y[i];

		// x의 최대값
		if (max_x == 20002)
		{
			max_x = bead_x[i];
		}
		else if (max_x < bead_x[i])
		{
			max_x = bead_x[i];
		}

		// x의 최소값
		if (min_x == -20002)
		{
			min_x = bead_x[i];
		}
		else if (min_x > bead_x[i])
		{
			min_x = bead_x[i];
		}

		// y의 최대값
		if (max_y == 20002)
		{
			max_y = bead_y[i];
		}
		else if (max_y < bead_y[i])
		{
			max_y = bead_y[i];
		}

		// y의 최소값
		if (min_y == -20002)
		{
			min_y = bead_y[i];
		}
		else if (min_y > bead_y[i])
		{
			min_y = bead_y[i];
		}
	}

	cout << (max_x - min_x) * (max_y - min_y);

}