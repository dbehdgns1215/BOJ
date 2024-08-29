#include <bits/stdc++.h>
using namespace std;

int apple, banana;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> apple >> banana;

	int human = min(apple, banana);

	for (int i = 1; i <= human; i++)
	{
		if (apple % i == 0)
		{
			if (banana % i == 0)
			{
				cout << i << " " << apple / i << " " << banana / i << "\n";
			}
		}
	}
}