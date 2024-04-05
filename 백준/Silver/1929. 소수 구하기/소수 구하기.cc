#include <bits/stdc++.h>
using namespace std;

/*
	기존 풀이는 O(N^2) 의 풀이로 시간초과가 날 수 밖에 없음. 입력값의 최대는 1,000,000임.
	조금 찾아보니 '에라토스테네스의 체' 라는 알고리즘이 있었음.

	사설이지만 만약 단일 숫자의 소수 판별을 해야한다면 O(N) 대신 O(1/2*N)으로 풀 수 있음. 8의 경우 약수가 1 2 4 8로
	2 * 4, 4 * 2 이렇게 대칭을 이루는 것을 알 수 있음. 결국 1하고 2만 확인하면 되는거임.

	다시 본론으로 돌아와서 에라토스테네스의 체는 다음과 같이 구현 가능.
	2부터 자기자신을 제외한 배수들을 쭉 지워나가면 됨.

	소수는 1과 자기자신만을 약수로 가짐 (1은 제외)
	참고자료 https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4
	*/

int m, n;
int arr[1000000]; // 전역변수에 선언 -> 0으로 자동 초기화.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n;
	
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == 1) continue; // 1이면 소수가 아니라는 뜻
		else {
			for (int k = i + i; k <= n; k += i)
			{
				if (arr[k] == 1) continue;
				arr[k] = 1;
			}
		}
	}

	arr[0] = 1;
	arr[1] = 1; // 0과 1은 소수가 아님.
	for (int i = m; i <= n; i++)
	{
		if (arr[i] == 0) { cout << i << "\n"; }
	}
}



/* 
기존 풀이

int m, n;
	cin >> m >> n;

	int p_num = 0;

	for (int i = m; i < n; i++)
	{
		int cnt = 0;
		for (int k = 1; k <= i; k++)
		{
			if (i % k == 0)
			{
				cnt++;
			}
		}
		if (cnt > 2) { continue; }
		else if (cnt == 0 || cnt == 1) { continue; }
		else { cout << i << "\n"; }
	}
*/