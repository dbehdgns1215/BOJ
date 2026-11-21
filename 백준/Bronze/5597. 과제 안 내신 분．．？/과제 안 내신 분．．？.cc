#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int att[30] = {}; // 0으로 초기화
	int yes;
	int no[2] = {};

	for (int i = 0; i < 28; i++)
	{
		cin >> yes;
		att[yes - 1] = -1; // 출석은 -1  미출석은 0
	}

	for (int k = 0; k < 30; k++)
	{
		if (att[k] == -1)
		{
			continue;
		}

		if (att[k] == 0)
			if (no[0] == 0)
			{
				no[0] = (k + 1);
			}
			else
				no[1] = (k + 1);
	}

	cout << no[0] << "\n" << no[1];

	
}