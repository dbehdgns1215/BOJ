#include<bits/stdc++.h>
using namespace std;

// 방향 이동: 오른쪽, 아래, 왼쪽, 위
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void solve(int test_case, int N) {
	vector<vector<int>> arr(N, vector<int>(N, 0)); // N x N 배열 초기화
	int x = 0, y = 0; // 시작 위치
	int dir = 0; // 방향 (0: 오른쪽, 1: 아래, 2: 왼쪽, 3: 위)
	int num = 1; // 채울 숫자

	while (num <= N * N) {
		arr[x][y] = num++; // 현재 위치에 숫자 채움

		// 다음 위치 계산
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// 경계 조건 확인 및 방향 변경
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] != 0) {
			dir = (dir + 1) % 4; // 방향 전환
			nx = x + dx[dir];
			ny = y + dy[dir];
		}

		// 위치 갱신
		x = nx;
		y = ny;
	}

	// 결과 출력
	cout << "#" << test_case << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
			if (j != N - 1) cout << " ";
		}
		cout << "\n";
	}
}

int main(int argc, char** argv) {
	int T; // 테스트 케이스 개수
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		solve(t, N); // 각 테스트 케이스에 대해 해결
	}

	return 0;
}