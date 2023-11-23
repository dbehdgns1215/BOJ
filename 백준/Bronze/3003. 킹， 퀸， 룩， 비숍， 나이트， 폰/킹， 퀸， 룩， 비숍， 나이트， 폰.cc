#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int white_piece[6] = { 1, 1, 2, 2, 2, 8 };
	int founded_white_piece[6];

	for (int i = 0; i < 6; i++)
	{
		cin >> founded_white_piece[i];
	}

	for (int i = 0; i < 6; i++)
	{
		cout << white_piece[i] - founded_white_piece[i] << " ";
	}
}