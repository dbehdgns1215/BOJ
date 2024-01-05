#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long A, B, C;
	cin >> A;
	cin >> B;
	cin >> C;

	long long result = A * B * C;
	string str = to_string(result);
	
	long long score[10] = { 0 };

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0') { score[0]++; }
		else if (str[i] == '1') { score[1]++; }
		else if (str[i] == '2') { score[2]++; }
		else if (str[i] == '3') { score[3]++; }
		else if (str[i] == '4') { score[4]++; }
		else if (str[i] == '5') { score[5]++; }
		else if (str[i] == '6') { score[6]++; }
		else if (str[i] == '7') { score[7]++; }
		else if (str[i] == '8') { score[8]++; }
		else if (str[i] == '9') { score[9]++; }
	}

	for (int i = 0; i < 10; i++)
	{
		cout << score[i] << "\n";
	}
}