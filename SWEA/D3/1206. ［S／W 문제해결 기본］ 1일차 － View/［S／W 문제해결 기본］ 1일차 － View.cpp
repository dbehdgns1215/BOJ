#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	int N;
	int arr[1001];

	for (test_case = 1; test_case <= T; test_case++)
	{
		int ans = 0;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		for (int i = 2; i < N - 2; i++) {
			int height;
			height = max(arr[i - 2], arr[i - 1]);
			height = max(height, arr[i + 1]);
			height = max(height, arr[i + 2]);

			int cnt = arr[i] - height;

			if (cnt < 0) { cnt = 0; }
			else { ans += cnt; }
		}

		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}