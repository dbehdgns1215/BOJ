#include <bits/stdc++.h>
using namespace std;

int n, k;
int a = 1, b = 1, c = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	// 이항계수 식		n!			  a
	//              ---------  == ---------
	//				 k!(n-k)!		 b(c)


	for (int i = n; i > 0; i--)
	{
		a *= i;
	}
	for (int i = k; i > 0; i--)
	{
		b *= i;
	}
	for (int i = n - k; i > 0; i--)
	{
		c *= i;
	}
	cout << a / (b * c); 
}