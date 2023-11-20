#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
	string s1, s2;

	cin >> s1 >> s2;


	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	if (s1 > s2)
	{
		cout << s1;
	}
	else cout << s2;

}
