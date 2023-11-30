#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str[15];

	for (int i = 0; i < 5; i++)
	{
		getline(cin, str[i]);
	}

	int size = str[0].length();
	for (int i = 1; i < 5; i++)
	{
		if (str[i].length() > size)
		{
			size = str[i].length();
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++)
		{
			if (i < str[j].length()) {
				cout << str[j][i];
			}
		}
	}
}