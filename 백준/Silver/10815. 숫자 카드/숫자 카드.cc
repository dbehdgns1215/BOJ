#include <bits/stdc++.h>
using namespace std;

vector <int> v;
int n;
int m;
int temp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		cout << binary_search(v.begin(), v.end(), temp) << " ";
		// binary_search()라는 함수는 특정 구간 내의 찾고자 하는 값이 있으면 1, 없으면 0 (T/F)를 반환해주는 함수.
	}
}