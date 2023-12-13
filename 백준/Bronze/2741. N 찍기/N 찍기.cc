#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int a = 1;

	while (1)
	{
		if (a > N) { return 0; }
		cout << a << "\n";
		a++;
	}
}