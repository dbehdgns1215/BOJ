#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int arr[101];
int bill;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B >> C;
	
	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;

		for (int i = start; i < end; i++) {
			arr[i]++;
		}
	}

	for (auto a : arr) {
		if (a == 1) {
			bill += A;
		}
		else if (a == 2) {
			bill += (B * 2);
		}
		else if (a == 3) {
			bill += (C * 3);
		}
	}

	cout << bill;
	return 0;
}