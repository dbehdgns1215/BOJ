#include <bits/stdc++.h>
using namespace std;

string op;
int n;
int q[2000001];
int init = 0; // 첫번째 인덱스를 가르킬 변수
int idx = 0; // a번 push 했을 때 a번째 인덱스를 가르킬 변수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> op; // 명령어 입력

		if (op == "push")
		{
			cin >> x;
			q[idx] = x;
			idx++; // 큐 전체 크기 + 1
		}
		else if (op == "pop")
		{
			if (idx == init) // idx == init -> 큐가 빈 상태
			{
				cout << "-1\n";
			}
			else {
				cout << q[init] << "\n";
				init++; // 배열 요소를 지우는 대신 init 값을 증가시키기
			}
		}
		else if (op == "size")
		{
			cout << idx - init << "\n";
		}
		else if (op == "empty")
		{
			if (idx == init)
			{
				cout << "1\n";
			}
			else { cout << "0\n"; }
		}
		else if (op == "front")
		{
			if (idx == init)
			{
				cout << "-1\n";
			}
			else { cout << q[init] << "\n"; } // 현재 첫번째 인덱스는 init
		}
		else if (op == "back")
		{
			if (idx == init)
			{
				cout << "-1\n";
			}
			else { cout << q[idx - 1] << "\n"; } // 현재 인덱스 -1 을 해줘야 제일 마지막에 추가한 인덱스 값 참조 가능
		}

	}
}