#include <bits/stdc++.h>
using namespace std;
using longlong = long long;

longlong POW(longlong a, longlong b, longlong m) {
	if (b == 1) return a % m;
	longlong val = POW(a, b / 2, m);
	val = val * val % m;
	if (b % 2 == 0) return val;
	return val * a % m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	longlong a, b, c;
	cin >> a >> b >> c;
	cout << POW(a, b, c);
}