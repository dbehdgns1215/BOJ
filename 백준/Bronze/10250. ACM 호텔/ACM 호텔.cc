#include<bits/stdc++.h>
using namespace std;

/*
	더 간단한 코드.. 층수와 호수 계산하다가 삐끗해서 너무 미련하게 푼 것 같다.
	#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int k = 0; k < T; k++) {
		int H, W, N;
		cin >> H >> W >> N;

		int floor = N % H;  // 손님이 머무는 층
		int room = N / H + 1;  // 손님이 머무는 호수

		// 만약 나머지가 0이면, 마지막 층에 머무는 것이므로 나머지를 H로 변경
		if (floor == 0) {
			floor = H;
			room -= 1;  // 호수를 수정
		}

		cout << floor * 100 + room << '\n';
	}

	return 0;
}
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int k = 0; k < T; k++)
	{
		int H, W, N;
		cin >> H >> W >> N;

		string hotel[100][100];

		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				string room;
				if (j < 10)
				{
					room = to_string(i) + to_string(0) + to_string(j);
				}
				else
				{
					room = to_string(i) + to_string(j);
				}
				hotel[i - 1][j - 1] = room;
			}
		}

		int cnt = 0;
		for (int i = 0; i < H;)
		{
			for (int j = 0; j < W;)
			{
				cnt++;
				if (cnt == N)
				{
					cout << hotel[i][j] << "\n";
					break;
				}
				i++;
				if (i == H)
				{
					i = 0;
					j++;
				}
			}
			break;
		}
	}
}