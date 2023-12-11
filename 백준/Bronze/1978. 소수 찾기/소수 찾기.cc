#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int p_num = 0;
	int num_cnt = 0;
	int N;
	
	int num[100];

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < N; i++)
	{
		num_cnt = 0;

		// 소수인지 확인
		for (int k = 1; k <= num[i]; k++)
		{
			if (num[i] % k == 0)
			{
				if (num[i] != 1) { num_cnt++; }
			}
		}

		// 약수가 2개 이상이면 이 숫자는 패스
		if (num_cnt > 2)
		{
			continue;
		}
		else if (num_cnt == 1 || num_cnt == 0)
		{
			continue;
		}
		else { p_num++; }
	}

	cout << p_num;
}