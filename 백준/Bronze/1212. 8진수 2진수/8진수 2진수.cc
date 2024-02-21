#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	string s;
	string binary[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
	int temp;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {

		temp = s[i] - '0';
		if (i == 0) cout << stoi(binary[temp]);
		else cout << binary[temp];
	}
}
