#include <bits/stdc++.h>
using namespace std;

int n;
string s[20001];

bool compare(const string& a, const string& b) {
	if (a.length() != b.length()) // 길이가 짧은 것부터
		return a.length() < b.length();
	else // 길이가 같으면 사전 순으로
		return a < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector<string> words;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		words.push_back(s[i]);
	}
	sort(words.begin(), words.end(), compare);

	// 중복 제거
	words.erase(unique(words.begin(), words.end()), words.end());

	for (int i = 0; i < words.size(); i++)
	{
		cout << words[i] << "\n";
	}
}
