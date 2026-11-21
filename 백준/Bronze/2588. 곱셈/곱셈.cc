#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, hund;
	int b_hund_cnt = 0;
	int b_ten_cnt = 0;
	int b_one_cnt = 0;
	int b_hund, b_ten, b_one;

	cin >> a >> b;

	hund = b;
	while (hund > 99)
	{
		hund = hund - 100;
		b_hund_cnt++;
	}
	b_hund = b_hund_cnt * 100;

	while (hund > 9)
	{
		hund = hund - 10;
		b_ten_cnt++;
	}
	b_ten = b_ten_cnt * 10;

	while (hund > 0)
	{
		hund = hund - 1;
		b_one_cnt++;
	}
	b_one = b_one_cnt;

	int first = a * (b_one);
	int second = a * (b_ten);
	int third = a * (b_hund);

	cout << first << "\n";
	cout << second  / 10 << "\n";
	cout << third / 100 << "\n";
	cout << first + second + third << "\n";
}
