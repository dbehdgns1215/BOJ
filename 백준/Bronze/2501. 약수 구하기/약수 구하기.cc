#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	int arr[10001];
	int cnt = 0;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
		{
			arr[i-1] = 1;
		}
		
	}

	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 1)
		{
			cnt++;

			if (cnt == K)
			{
				cout << i + 1;
			}
		}
	}
	if (cnt < K)
	{
		cout << 0;
	}
}