#include <bits/stdc++.h>
using namespace std;

int N, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    while (N--) {
        string text;
        cin >> text;

        vector<char> s;
        for (char c : text) {
            if (!s.empty() && s.back() == c) {
                s.pop_back();
            } else {
                s.push_back(c);
            }
        }
        if (s.empty()) cnt++;
    }

    cout << cnt;
}
