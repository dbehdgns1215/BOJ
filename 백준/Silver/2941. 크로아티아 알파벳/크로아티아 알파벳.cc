#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;

	cin >> s;

	int alphabet = s.length();

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'c')
		{
			if (s[i + 1] == '=' || s[i + 1] == '-')
			{
				alphabet--;
			}
		}
		if (s[i] == 'd')
		{
			if (s[i + 1] == 'z')
			{
				if (s[i + 2] == '=')
				{
					alphabet -= 2;
				}
			}
			else if (s[i + 1] == '-')
			{
				alphabet--;
			}
		}
		if (s[i] == 'l')
		{
			if (s[i + 1] == 'j')
			{
				alphabet--;
			}
		}
		if (s[i] == 'n')
		{
			if (s[i + 1] == 'j')
			{
				alphabet--;
			}
		}
		if (s[i] == 's')
		{
			if (s[i + 1] == '=')
			{
				alphabet--;
			}
		}
		if (s[i] == 'z')
		{
			if (s[i + 1] == '=')
			{
				if (s[i - 1] != 'd')
				{
					alphabet--;
				}
			}
		}
	}

	
	cout << alphabet;
}