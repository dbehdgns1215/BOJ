#include <bits/stdc++.h>
using namespace std;

int H, x;
int m = 1000000000 + 7;
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> H >> x;
	 
	long long snowball = 1;

	while (H--)
	{
		snowball = (snowball * x) % m;

		long long snowball_Cnt;
		cin >> snowball_Cnt;

		ans += ((snowball % m) * (snowball_Cnt % m)) % m;
	}

	cout << ans % m;
}