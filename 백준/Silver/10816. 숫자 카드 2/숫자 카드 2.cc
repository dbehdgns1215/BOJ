#include <bits/stdc++.h>
using namespace std;

int n, m;
map <int, int> card;
vector<int> num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int idx;
		cin >> idx;
		card[idx]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int idx;
		cin >> idx;
		num.push_back(idx);
	}

	for (int i = 0; i < m; i++)
	{
		cout << card[num[i]] << " ";
	}
}

/*
map 사용법
#include <map>
#include <iostream>
using namespace std;

int main() {
    map<string, int> m;

    // 삽입: insert 메서드 사용
    m.insert(pair<string, int>("apple", 100));
    m.insert(pair<string, int>("banana", 200));

    // 삽입: [] 연산자 사용
    m["orange"] = 300;

    // 검색: find 메서드 사용
    if (m.find("apple") != m.end()) {
        cout << "apple is in the map" << endl;
    } else {
        cout << "apple is not in the map" << endl;
    }

    // 삭제: erase 메서드 사용
    m.erase("banana");

    // 값 수정: [] 연산자 사용
    m["apple"] = 150;

    // 모든 원소 출력
    for(auto itr = m.begin(); itr != m.end(); itr++) {
        cout << itr->first << ": " << itr->second << endl;
    }

    return 0;
}
*/