#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int k, int pos) { // 현재 k개까지 수를 택했고, pos 이후의 수를 고려한다
	if (k == m) { // m개 모두 택했을 시 기저조건 발동
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = pos; i <= n; i++) // pos부터 n까지의 수에 대해
	{
		arr[k] = i; // k번째 수를 i로 정함
		func(k + 1, i + 1); // 다음 수를 정하러 한 단계 더 진입
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	func(0, 1);
}
