#include <bits/stdc++.h>
using namespace std;

int arr[5];
int sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 5);
	
	int avg = sum / 5;
	cout << avg << "\n" << arr[2];
}