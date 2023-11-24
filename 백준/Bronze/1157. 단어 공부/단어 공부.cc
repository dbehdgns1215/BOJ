#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;

	cin >> str;

	int cnt[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	for (int i = 0; i < str.length(); i++)
	{
		if ((int)str[i] > 64 && (int)str[i] < 91)
		{
			cnt[(int)str[i] - 65] += 1;
		}
		else if ((int)str[i] > 96 && (int)str[i] < 123)
		{
			cnt[(int)str[i] - 97] += 1;
		}
	}
	
	int big = -1;
	char result;

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] > big)
		{
			big = cnt[i];
			result = (char)(i + 65);
		}
		else if (cnt[i] == big)
		{
			result = '?';
		}
	}

	cout << result;

}