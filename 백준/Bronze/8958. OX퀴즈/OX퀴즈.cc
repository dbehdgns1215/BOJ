#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		string test;
		cin >> test;
		int sum = 0;
		int score = 0;
		for (int k = 0; k < test.length(); k++)
		{
			if (test[k] == 'O')
			{
				score++;
				sum += score;
			}
			else if (test[k] == 'X')
			{
				score = 0;
			}
		}

		cout << sum << "\n";
	}
}