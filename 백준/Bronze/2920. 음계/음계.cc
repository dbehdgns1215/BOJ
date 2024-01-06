#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int C_major_asc[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int C_major_des[8] = { 8, 7, 6, 5, 4, 3, 2, 1 };

	int C_major[8];

	for (int i = 0; i < 8; i++)
	{
		cin >> C_major[i];
	}
	
	if (equal(C_major, C_major + 8, C_major_asc, C_major_asc + 8))
	{
		cout << "ascending";
		return 0;
	}
	else if (equal(C_major, C_major + 8, C_major_des, C_major_des + 8))
	{
		cout << "descending";
		return 0;
	}
	else cout << "mixed"; return 0;
}