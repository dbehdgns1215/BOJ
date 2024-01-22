#include <bits/stdc++.h>
using namespace std;

/*
[전제 조건]

<명제>
현재 시간이 t일 때 시작 시간이 t 이상인 모든 회의 중에서
가장 먼저 종료하는 회의를 택하는 것이 최적의 해이다.

명제를 거짓이라고 가정했을 때
반례가 하나라도 있다면 본 명제를 참으로 봐도 타당함.

즉 t 이상인 모든 회의 중에서 가장 먼저 종료하지 않는 회의들을 골랐을 때가
가장 먼저 종료하는 회의를 골랐을 때보다 더 많은 회의수가 생긴다는 것을 증명해야 함.

만약 두 번째로 먼저 끝나는 회의를 선택했다고 가정해보자.
첫 번째로 먼저 끝나는 회의보다 두 번째로 먼저 끝나는 회의의 시작시간이 느리다면
결국 두 번째로 먼저 끝나는 회의를 첫 번째로 먼저 끝나는 회의가 포함하고 있는 구조이다.
(회의 1 : 3 ~ 5    회의 2 : 6 ~ 7) 회의 1은 회의 2의 범위를 포함한다.

그렇기에 우리는 앞선 명제의 역에서 반례를 찾았기에 본 명제가 참임을 알 수 있다.
*/

#define END first // 종료 시각
#define START second // 시작 시각

int n;
pair<int, int> using_time[100002]; // { 종료 시각, 시작 시각 }


int main() {
	cin >> n;
	int ans = 0; // 회의 수
	int t = 0; // 현재 시각

	for (int i = 0; i < n; i++)
	{
		cin >> using_time[i].START >> using_time[i].END;
	}
	sort(using_time, using_time + n); // 첫 번째 인자로 종료 시각을 넣어서 종료 시각을 기준으로 오름차순 정렬.

	for (int i = 0; i < n; i++)
	{
		if (t > using_time[i].START) continue; // 현재 시각보다 일찍 시작하는 회의는 스킵.
		ans++;
		t = using_time[i].END;
	}
	cout << ans;
}