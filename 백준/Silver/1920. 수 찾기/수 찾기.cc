#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, num;
    set<int> s;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        s.insert(num);
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> num;
        if(s.find(num) != s.end()) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}
