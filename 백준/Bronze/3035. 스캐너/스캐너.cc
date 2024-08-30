#include <bits/stdc++.h>
using namespace std;

int R, C, ZR, ZC;
char paper[51][51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C >> ZR >> ZC;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int p = 0; p < ZR; p++)
		{
			for (int j = 0; j < C; j++)
			{
				for (int k = 0; k < ZC; k++)
				{
					cout << paper[i][j];
				}
			}
			cout << "\n";
		}
	}
}