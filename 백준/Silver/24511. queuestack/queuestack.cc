#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int N;
int a[100001]; // 원본 배열
int b[100001]; // 큐 or 스택 배열
int M; // 삽입할 수열 길이
int c[100001]; // 삽입할 수열
int st;
deque<int> s;
queue<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> st;
		if (st == 0) {
			b[i] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < N; i++) {
		if (b[i]) {
			s.push_back(a[i]);
		}
	}


	cin >> M;


	for (int i = 0; i < M; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < M; i++) {
		if (!s.empty()) {
			auto a = s.back();
			s.pop_back();
			ans.push(a);
			s.push_front(c[i]);
		}
		else {
			ans.push(c[i]);
		}
	}

	for (int i = 0; i < M; i++) {
		if (!ans.empty()) {
			int temp = ans.front();
			ans.pop();
			cout << temp << " ";
		}
	}
}