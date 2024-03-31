#include <bits/stdc++.h>
using namespace std;

int L;
string s;
long long r = 1;
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L;
	cin >> s;

	for (int i = 0; i < L; i++)
	{
		ans += (s[i] - 96) * r;
		r *= 31;
	}
	cout << ans % 1234567891;
}