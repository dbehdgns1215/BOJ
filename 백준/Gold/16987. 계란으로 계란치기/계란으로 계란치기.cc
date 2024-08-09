#include <bits/stdc++.h>
using namespace std;

#define Def first 
#define Atk second

int n;
vector <pair<int, int>> eggs;
int maxBrokenCnt;

void func(int k)
{
	if (k == n) // n개의 계란을 모두 사용한 케이스가 이 부분에 걸리게 됨
	{
		int brokenCnt = 0;
		for (int i = 0; i < n; i++) {
			if (eggs[i].Def <= 0) { // 계란이 깨진 경우
				brokenCnt++;
			}
		}
		maxBrokenCnt = max(maxBrokenCnt, brokenCnt);
		return;
	}

	if (eggs[k].Def <= 0) {
		func(k + 1);
		return;
	}


	bool allBroken = true;
	for (int i = 0; i < n; i++)
	{
		if (k != i && eggs[i].Def > 0) {
			allBroken = false;

			eggs[k].Def -= eggs[i].Atk;
			eggs[i].Def -= eggs[k].Atk;

			func(k + 1);

			eggs[k].Def += eggs[i].Atk;
			eggs[i].Def += eggs[k].Atk;
		}
	}

	if (allBroken) {
		func(k + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		auto temp = make_pair(temp1, temp2);
		eggs.push_back(temp);
	}

	func(0);
	cout << maxBrokenCnt;
}