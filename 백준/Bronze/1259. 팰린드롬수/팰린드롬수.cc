#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string palindromeNum;
	
	while (1)
	{
		cin >> palindromeNum;
		if (palindromeNum == "0") { return 0; }
		string temp;
		temp = palindromeNum;
		reverse(temp.begin(), temp.end());

		if (palindromeNum.compare(temp) == 0)
		{
			cout << "yes\n";
		}
		else { cout << "no\n"; }
	}
}