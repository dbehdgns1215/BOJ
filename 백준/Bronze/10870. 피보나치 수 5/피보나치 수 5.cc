#include <bits/stdc++.h>
using namespace std;

int N;

int sum = 0;

long long fibo(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibo(n - 1) + fibo(n - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	long long ans = fibo(N);
	cout << ans;
}