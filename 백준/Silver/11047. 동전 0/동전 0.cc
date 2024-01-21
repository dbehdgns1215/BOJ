#include <bits/stdc++.h>
using namespace std;

int N, K;
int g[15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans = 0;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++)
	{
		cin >> g[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		ans = ans + K / g[i];
		K = K % g[i];
	}
	cout << ans;
}