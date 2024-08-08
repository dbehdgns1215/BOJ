#include <bits/stdc++.h>
using namespace std;

int l, c;
vector <char> eng;
vector <char> cipher;

int vowel_cnt, consonant_cnt;

bool isVowel(char eng) {
	return eng == 'a' || eng == 'e' || eng == 'i' || eng == 'o' || eng == 'u';
}

void func(int k, int start) {
	if (k == l && vowel_cnt >= 1 && consonant_cnt >= 2)
	{
		for (int i = 0; i < l; i++)
		{
			cout << cipher[i];
		}
		cout << "\n";
		return;
	}
	else if (k == l && (vowel_cnt < 1 || consonant_cnt < 2))
	{
		return;
	}

	for (int i = start; i < c; i++)
	{
		if (isVowel(eng[i]))
		{
			vowel_cnt++;
		}
		else {
			consonant_cnt++;
		}

		cipher.push_back(eng[i]);
		func(k + 1, i + 1);
		cipher.pop_back();

		if (isVowel(eng[i]))
		{
			vowel_cnt--;
		}
		else {
			consonant_cnt--;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		char temp;
		cin >> temp;
		eng.push_back(temp);
	}

	sort(eng.begin(), eng.end());

	func(0, 0);
}