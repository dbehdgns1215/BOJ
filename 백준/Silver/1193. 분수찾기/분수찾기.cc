#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int X;
    cin >> X;

    int line = 1;
    while (X > line) {
        X -= line;
        line++;
    }

    if (line % 2 == 0) {
        cout << X << "/" << line + 1 - X;
    } else {
        cout << line + 1 - X << "/" << X;
    }
}
