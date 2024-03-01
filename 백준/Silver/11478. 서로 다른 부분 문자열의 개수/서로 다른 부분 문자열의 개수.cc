#include <bits/stdc++.h>
using namespace std;

set<string> s; 
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = i; j < str.length(); j++)
		{
			s.insert(str.substr(i, j - i + 1));
		}
	}
	cout << s.size(); 
}