#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int line[3];
	
	while (1)
	{
		cin >> line[0] >> line[1] >> line[2];
		if (line[0] == 0 && line[1] == 0 && line[2] == 0) { return 0; }

		sort(line, line + 3);
		
		int a = line[0] * line[0];
		int b = line[1] * line[1];
		int c = line[2] * line[2];
		if (a + b == c)
		{
			cout << "right\n";
		}
		else cout << "wrong\n";
	}
}