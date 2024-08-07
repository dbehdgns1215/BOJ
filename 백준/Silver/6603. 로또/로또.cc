#include <bits/stdc++.h>
using namespace std;

int k;
vector <int> s;
vector <int> lotto;

void func(int l, int start) {
	if (l == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << lotto[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < k; i++)
	{
		lotto.push_back(s[i]);
		func(l + 1, i + 1);
		lotto.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	do {
		cin >> k;

		if (!s.empty())
		{
			while (!s.empty())
			{
				s.pop_back();
			}
		}

		for (int i = 0; i < k; i++)
		{
			int temp;
			cin >> temp;
			s.push_back(temp);
		}

		sort(s.begin(), s.end());

		func(0, 0);
		cout << "\n";
	} while (k != 0);

}