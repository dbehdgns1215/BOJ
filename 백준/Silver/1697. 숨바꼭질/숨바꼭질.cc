#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[100002];
int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	fill(dist, dist + 100001, -1);

	dist[n] = 0; // 수빈이 위치
	
	queue<int> Q;
	Q.push(n);

	while (dist[k] == -1)
	{
		auto cur = Q.front(); Q.pop();
		// 범위 기반 for문.. 수빈이의 선택지는 -1칸 이동 +1칸 이동 X2칸 이동 뿐
		for (int nxt : {cur - 1, cur + 1, cur * 2}) {
			if (nxt < 0 || nxt > 100000) continue; // nxt -> cur -> n -> 수빈이 위치
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}
	cout << dist[k];
}