#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;

	cin >> s;

	int alpha[26];

	for (int a = 0; a < 26; a++) // 기본 값 -1로 초기화
	{
		alpha[a] = -1;
	}

	for (int i = 0; i < s.length(); i++) 
	{
		if (alpha[(int)s[i] - 97] != -1) // 배열 인덱스로 사용하기 위해서 1을 더 빼줬음.
		{
			continue; // 소문자 a = 97, 대문자 A = 65
		}
		alpha[(int)s[i] - 97] = i;
	}

	for (int b = 0; b < 26; b++)
	{
		cout << alpha[b] << " ";
	}
}