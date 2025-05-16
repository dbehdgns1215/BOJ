#include <bits/stdc++.h>
using namespace std;

int N;
long long ans = 1;

long long func(int n) {
	if (n == 1) {
		return ans;
	}
	ans *= n;
	return func(n - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	if (N == 0) {
		cout << "1";
		return 0;
	}

	long long answer = func(N);
	cout << answer;
	return 0;
}