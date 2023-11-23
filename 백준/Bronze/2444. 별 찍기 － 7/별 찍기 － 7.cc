#include <bits/stdc++.h>
using namespace std;

int main() {
	int cnt;

	cin >> cnt;
	
	for (int i = 0; i < cnt; i++)
	{
		for (int j = cnt - i - 1; j > 0; j--)
		{
			cout << " ";
		}
		for (int j = cnt - 1; j < cnt + (i * 2); j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	for (int i = cnt; i > 1; i--)
	{
		for (int j =  0; j < cnt - i + 1; j++)
		{
			cout << " ";
		}
		for (int j = 1; j < 2 * i - 2; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
    
}