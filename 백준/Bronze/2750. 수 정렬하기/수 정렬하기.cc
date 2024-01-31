#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	
	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}
}