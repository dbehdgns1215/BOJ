#include <bits/stdc++.h>
using namespace std;

int HH, mm;
int minute;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> HH >> mm;

	minute += (HH * 60);
	minute += mm;

	cout << minute - (9 * 60);
}