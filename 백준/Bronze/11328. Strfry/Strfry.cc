#include <bits/stdc++.h>
using namespace std;

int n;
int arr[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;


	while (n--)
	{
		for (int i = 0; i < 26; i++)
		{
			arr[i] = 0;
		}

		string a1;
		string a2;

		cin >> a1;
		cin >> a2;

		if (a1.length() != a2.length()) { cout << "Impossible\n"; continue; }

		for (int i = 0; i < a1.length(); i++)
		{
			char temp = a1[i];
			arr[(int)temp - 97]++;
		}

		for (int i = 0; i < a2.length(); i++)
		{
			char temp = a2[i];
			arr[(int)temp - 97]--;
		}

		bool isFind = false;
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] > 0) { isFind = true; }
		}

		if (isFind)
		{
			cout << "Impossible\n";
		}
		else cout << "Possible\n";
	}
}