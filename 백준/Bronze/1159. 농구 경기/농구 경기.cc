#include <bits/stdc++.h>
using namespace std;

int N;
char arr[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;

		arr[name[0] - 'a']++;
	}

	bool isFinish = false;

	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			cout << (char)('a' + i);
			isFinish = true;
		}
	}

	if (!isFinish) { cout << "PREDAJA"; }
}