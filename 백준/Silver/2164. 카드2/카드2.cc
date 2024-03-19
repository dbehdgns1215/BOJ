#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	queue <int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while (--n)
	{
		int temp;
		q.pop();
		temp = q.front();
		q.pop();
		q.push(temp);
	}
	cout << q.front();
}