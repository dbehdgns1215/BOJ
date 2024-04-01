#include <bits/stdc++.h>
using namespace std;


/* 만약에 1번 사람이 2번 사람보다 확실히 작아서 등수가 2등이 되었다고 가정해보자.
그리고 1번 사람이 3번 사람보다 확실히 작아서 등수가 3등이 되었어

그런데 만약에 3번 사람이 2번사람보다 작아서 등수가 2등이 되고
3번 사람이 5번 사람보다 작아서 등수가 3등이 되면

1번 사람이 모든 경우의 수를 확인했을 때 3등이 되는거고
3번 사람도 3등이 되는거잖아 ?

근데 1번과 3번은 사실 3번이 더 큰거니까 1번 사람은 4등이 되어야하는거 아니야 ?

-> 문제의 핵심은 다음과 같다.
	만일 자신보다 더 큰 덩치의 사람이 k명이라면 그 사람의 덩치 등수는 k+1이 된다.
	이렇게 등수를 결정하면 같은 덩치 등수를 가진 사람은 여러 명도 가능하다.

결과적으로 앞선 의문처럼 1번이 4등이 될 필요가 없음.
1번보다 큰 사람이 2명이니까 등수가 3이 되는거고
3번보다 큰 사람이 2명이니까 등수가 3이 되는거임.

그리고 저 문제가 사실 오류가 있는데
1 < 3 인 상태에서 3 < 5 이면 1 < 5니까 1번 사람은 무조건 4등이 되는거긴 함.
아무튼 문제 속에 핵심이 들어있었음.
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <pair<int, int>> people;
	vector <int> rank(n, 1);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		people.push_back(make_pair(x, y));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (people[i].first < people[j].first && people[i].second < people[j].second) {
					// i번째 사람이 j번째 사람보다 몸무게와 키 모두 작은 경우, i번째 사람의 등수를 증가시킴
					rank[i]++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << rank[i] << ' ';
	}
	cout << '\n';
}