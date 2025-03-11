#include <bits/stdc++.h>
using namespace std;

int N, K;
int psum[100001];
int temp;
int ans = INT_MIN;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> temp;
		psum[i] = psum[i - 1] + temp;
	}

	for (int i = K; i <= N; i++) {
		ans = max(psum[i] - psum[i - K], ans);
	}
	cout << ans;
}