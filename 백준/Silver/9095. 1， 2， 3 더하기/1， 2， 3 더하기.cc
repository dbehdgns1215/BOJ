#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int D[12];
	int T, N;

	cin >> T;
	
	for (int k = 0; k < T; k++)
	{
		cin >> N;

		D[1] = 1;
		D[2] = 2;
		D[3] = 4;

		for (int i = 4; i <= N; i++)
		{
			D[i] = D[i - 1] + D[i - 2] + D[i - 3];
		}
		cout << D[N] << "\n";
	}
}