#include <bits/stdc++.h>
using namespace std;

map <string, int> book;
vector<string> name;
int n, m;

bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]) == 0)
		{
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	name.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		string temp;
		cin >> temp;
		name[i] = temp;
		book[temp] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		string temp;
		cin >> temp;
		if (isNumber(temp))
		{
			int idx = stoi(temp);
			cout << name[idx] << "\n";
		}
		else
		{
			cout << book[temp] << "\n";
		}
	}
}