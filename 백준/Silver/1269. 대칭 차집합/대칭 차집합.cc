#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
int result = 0;
map<int, int> countMap;
set<int> unionSet;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        unionSet.insert(temp);
        countMap[temp]++;
    }

    for (int i = 0; i < m; i++) {
        cin >> temp;
        unionSet.insert(temp);
        countMap[temp]--;
    }

    for (auto element : unionSet) {
        if (countMap[element] != 0) {
            result++;
        }
    }

    cout << result << "\n";

}
