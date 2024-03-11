#include <bits/stdc++.h>
using namespace std;

int tree[100001]; // 가로수의 위치 
vector<int> tree_distance;

int N;	// 가로수의 개수
int tree_gcd;	// 가로수의 간격들의 최대공약수
int cnt;

// 유클리드 호제법 공식. gcd(a, b) = gcd(b, r) (단, a = q*b + r 라고 가정했을 때)
long long gcd(long long a, long long b) {
	while (b != 0) {
		long long temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
	}
	sort(tree, tree + N);

	// 가로수들 사이의 간격 구하기
	for (int i = 0; i < N - 1; i++) {
		int dist = tree[i + 1] - tree[i];
		tree_distance.push_back(dist);
	}

	// 가로수들의 간격의 최대공약수 구하기
	for (int i = 0; i < N - 1; i++) {
		tree_gcd = gcd(tree_gcd, tree_distance[i]);
	}

	// 가로수들 사이의 간격을 최대공약수로 나누어 몇개를 추가로 심어야 하는지 구하기
	for (int i = 0; i < N - 1; i++) {
		// 양끝에 이미 하나씩 심어져 있으므로 -1
		cnt += (tree_distance[i] / tree_gcd) - 1;
	}

	cout << cnt;
}