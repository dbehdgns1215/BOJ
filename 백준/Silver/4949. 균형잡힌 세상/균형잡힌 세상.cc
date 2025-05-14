#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		string s;
		getline(cin, s);
		if (s == ".") break;

		stack<char> stk;

		bool flag = true;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
				stk.push(s[i]);
			}

			if (s[i] == ']') {
				if (!stk.empty() && stk.top() == '[') stk.pop();
				else {
					cout << "no\n";
					flag = false;
					break;
				} 
			}
			if (s[i] == '}') {
				if (!stk.empty() && stk.top() == '{') stk.pop();
				else {
					cout << "no\n";
					flag = false;
					break;
				}
			}
			if (s[i] == ')') {
				if (!stk.empty() && stk.top() == '(') stk.pop();
				else {
					cout << "no\n";
					flag = false;
					break;
				}
			}
				
		}

		if (stk.empty() && flag) {
			cout << "yes\n";
		}
		else if (!stk.empty() && flag) {
			cout << "no\n";
		}
	}

	return 0;
}