#include <bits/stdc++.h>
using namespace std;

string text;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	getline(cin, text);

	for (int i = 0; i < text.length(); i++) {
		if (text[i] >= 'A' && text[i] <= 'Z') {
			if (text[i] > ('Z' - 13)) {
				text[i] -= 26;
				text[i] += 13;
			}
			else (text[i] += 13);
		}
		else if (text[i] >= 'a' && text[i] <= 'z') {
			if (text[i] > ('z' - 13)) {
				text[i] -= 26;
				text[i] += 13;
			}
			else (text[i] += 13);
		}
	}

	for (auto a : text) cout << a;
}