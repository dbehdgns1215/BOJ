#include <bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;

    cin >> N;

    if (N == 1) { return 0; }
    for (int i = 2; i <= N; i++) {
        while (N % i == 0) {
            cout << i << '\n';
            N /= i;
        }
	}
}