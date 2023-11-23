#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;

	cin >> str;

	int end = str.length() - 1;

	int palindromes = 1;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == str[end]) { end--;  continue; }
		else palindromes = 0;
	}

	cout << palindromes;
}