#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void func(int k) { // 현재 k개까지 수를 택함
	if (k == m) { //  m개 모두 택했을 시 기저조건 발동
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) // 1부터 n까지의 수에 대해
	{
		if (!isUsed[i]) { // 아직 i가 사용된 수가 아니면
			// 현재 수 
			arr[k] = i; // k번째 수를 i로 정함
			// 다음 수
			isUsed[i] = 1; // i를 사용되었다고 표시
			// 재귀 호출
			func(k + 1); // 다음 수를 정하러 한 단계 더 진입
			// 재귀 끝내서 돌아온 뒤 다음 수
			isUsed[i] = 0; // k번째 수를 i로 정한 모든 경우를 확인 완료했으니 i를 이제 사용되지 않았다고 표시
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	func(0);
}