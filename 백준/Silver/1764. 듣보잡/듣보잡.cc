#include <bits/stdc++.h>
using namespace std;

map<string, int> nameCount;
vector<string> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n + m; i++) {
        string name;
        cin >> name;
        nameCount[name]++;
    }

    for (auto pair : nameCount) {
        if (pair.second > 1) {
            ans.push_back(pair.first);
        }
    }

    cout << ans.size() << "\n";
    for (string name : ans) 
        cout << name << '\n';{
    }
}
