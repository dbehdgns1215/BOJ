#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;

int main() {
	while (scanf("%d", &N) != EOF) {
		int cnt = 1, ans = 1;
		while (true) {
			if (cnt % N == 0) {
				cout << ans << "\n";
				break;
			}
			else {
				cnt = (cnt * 10) + 1;
				cnt %= N;
				ans++;
			}
		}
	}
	return 0;
}