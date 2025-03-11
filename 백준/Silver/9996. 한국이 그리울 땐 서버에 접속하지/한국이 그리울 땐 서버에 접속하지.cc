#include <bits/stdc++.h>
using namespace std;

int N;
string pat;
string pre, suf;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	cin >> pat;
	
	int pos = pat.find('*');
	pre = pat.substr(0, pos);
	suf = pat.substr(pos + 1);

	for (int i = 0; i < N; i++) { 
		string text;
		cin >> text;

		if (pre.size() + suf.size() > text.size()) {
			cout << "NE\n";
		}
		else {
			if (pre == text.substr(0, pre.size()) && suf == text.substr(text.size() - suf.size())) cout << "DA\n";
			else cout << "NE\n";
		}
	}
	return 0; 
}