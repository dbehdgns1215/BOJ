#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;

	cin >> a >> b >> c;

	int length[3] = { a, b, c };
	
	sort(length, length + 3);

	if (length[0] + length[1] > length[2])
	{
		cout << length[0] + length[1] + length[2];
	}
	else
	{
		cout << (length[0] + length[1]) * 2 - 1;
	}
}