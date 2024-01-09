#include <bits/stdc++.h>
using namespace std;

// 테이블 정의
// D[i][0] = i번째 집을 칠할 때 까지의 최솟값, i번째 집은 빨강
// D[i][1] = i번째 집을 칠할 때 까지의 최솟값, i번째 집은 초록
// D[i][2] = i번째 집을 칠할 때 까지의 최솟값, i번째 집은 파랑

// 점화식 찾기
// D[k][0] = min(D[k-1][1], D[k-1][2]) + R(K)
// D[k][1] = min(D[k-1][0], D[k-1][2]) + G(K)
// D[k][2] = min(D[k-1][0], D[k-1][1]) + B(K)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int R[1002], G[1002], B[1002];
	int D[1002][3];

	for (int i = 1; i <= N; i++)
	{
		cin >> R[i] >> G[i] >> B[i];
	}
	D[1][0] = R[1];
	D[1][1] = G[1];
	D[1][2] = B[1];

	for (int i = 2; i <= N; i++)
	{
		D[i][0] = min(D[i - 1][1], D[i - 1][2]) + R[i];
		D[i][1] = min(D[i - 1][0], D[i - 1][2]) + G[i];
		D[i][2] = min(D[i - 1][0], D[i - 1][1]) + B[i];
	}
	cout << min(D[N][0], min(D[N][1], D[N][2]));
}