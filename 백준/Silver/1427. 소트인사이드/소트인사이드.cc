#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;

    sort(N.begin(), N.end(), greater<char>());

    cout << N;
}
