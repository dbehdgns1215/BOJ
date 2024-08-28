#include <bits/stdc++.h>
using namespace std;

string word;
int sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> word;
	if (word == "a")
	{
		cout << "It is a prime word.";
		return 0;
	}

	for (int i = 0; i < word.size(); i++)
	{
		if ((int)word[i] > 64 && (int)word[i] < 91)
		{
			sum += ((int)word[i] - 38);
		}
		else if ((int)word[i] > 96 && (int)word[i] < 123)
		{
			sum += ((int)word[i] - 96);
		}
	}

	for (int i = 2; i <= sqrt(sum); i++) { 
		if (sum % i == 0) { 
			cout << "It is not a prime word.";
			return 0;
		}
	}
	cout << "It is a prime word.";

	return 0;
	
}