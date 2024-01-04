#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int D[301];
	int arr[301];
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	// 초기값
	D[0] = 0;
	D[1] = arr[1];
	D[2] = arr[1] + arr[2];

	for (int i = 3; i <= N; ++i)
	{
		D[i] = max(D[i - 2] + arr[i], D[i - 3] + arr[i - 1] + arr[i]); // 점화식
	}
		
	cout << D[N];
}