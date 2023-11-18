#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, r;
	string qr_code;
	string result;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> r >> qr_code;

		for (int j = 0; j < qr_code.length(); j++)
		{
			for (int k = 0; k < r; k++)
			{
				result += qr_code[j];
			}	
		}
		result += "\n";
	}

	cout << result;

}