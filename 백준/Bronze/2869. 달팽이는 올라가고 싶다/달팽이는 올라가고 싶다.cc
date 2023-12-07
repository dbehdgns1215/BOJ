#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, V;
	int dist = 0;
	int day;

	cin >> A >> B >> V;

	if ((V - A) % (A - B) == 0) {
		day = (V - A) / (A - B);
	}
	else
	{
		day = (V - A) / (A - B) + 1;
	}
	cout << day + 1;
}