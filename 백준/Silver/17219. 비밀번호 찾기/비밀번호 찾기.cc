#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // 저장된 주소 수, 비밀번호 찾으려는 주소 수
    cin >> n >> m;

    map<string, string> mp; // 사이트 주소를 키로, 비밀번호를 값으로 하는 map

    for (int i = 0; i < n; i++) {
        string url, pw;
        cin >> url >> pw;
        mp[url] = pw; // map에 저장
    }

    for (int i = 0; i < m; i++) {
        string target;
        cin >> target;
        cout << mp[target] << "\n"; // map에서 바로 비밀번호 찾아 출력
    }
}
