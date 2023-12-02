#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int B;
	string N;
	int length;

	cin >> N >> B;
	length = N.length();

	int result = 0;

	for (int i = 0; i < length; i++)
	{
		if (N[i] >= '0' && N[i] <= '9')
		{
			result += ((int)N[i] - '0') * (int)pow(B, length - 1 - i);
		}
		else
		{
			result += ((int)N[i] - 'A' + 10) * (int)pow(B, length - 1 - i);
		}
	}

	cout << result;
}