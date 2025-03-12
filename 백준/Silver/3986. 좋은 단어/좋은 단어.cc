#include <bits/stdc++.h>
using namespace std;

int N;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string text;
		cin >> text;

		stack<char> s;

		for (int k = 0; k < text.length(); k++) {
			if (!s.empty()) {
				if (s.top() == text[k]) {
					s.pop();
					continue;
				}
				else {
					s.push(text[k]);
				}
			}
			else { s.push(text[k]); }
		}

		if (s.empty()) { cnt++; }
	}
	cout << cnt;
}