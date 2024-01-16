#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int N;

int isUsed1[227];
int isUsed2[227];
int isUsed3[227];

void func(int cur) {
	if (cur == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (isUsed1[i] || isUsed2[cur + i] || isUsed3[cur - i + N - 1])
		{
			continue;
		}
		isUsed1[i] = 1;
		isUsed2[cur + i] = 1;
		isUsed3[cur - i + N - 1] = 1;
		func(cur + 1);
		isUsed1[i] = 0;
		isUsed2[cur + i] = 0;
		isUsed3[cur - i + N - 1] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	func(0);
	cout << cnt;
}