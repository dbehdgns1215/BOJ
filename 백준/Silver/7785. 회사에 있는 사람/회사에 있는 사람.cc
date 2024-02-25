#include <bits/stdc++.h>
using namespace std;

int n;
map<string, string> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
    for (int i = 0; i < n; i++) {
        string name, state;
        cin >> name >> state;
        if (state == "enter") {
            m[name] = 1;
        }
        else if (state == "leave") {
            m.erase(name);
        }
    }

	for (auto iter = m.rbegin(); iter != m.rend(); iter++) {
		cout << iter->first << "\n";
	}
}