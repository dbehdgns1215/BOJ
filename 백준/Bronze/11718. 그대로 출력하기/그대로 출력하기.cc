#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s[100];


	for (int i = 0; i < 100; i++)
	{
		getline(cin, s[i]);

		if (s[i].empty()) break;
	}

	for (int i = 0; i < 100; i++) {
		if (s[i].empty())
			break;

		cout << s[i] << "\n";
	}



}