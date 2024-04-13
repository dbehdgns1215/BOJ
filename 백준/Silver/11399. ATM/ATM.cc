#include <bits/stdc++.h>
using namespace std;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector <int> v;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	
	int time = 0;
	for (int i = 0; i < n; i++)
	{
		time += (v.at(i)) * (n - i);
	}

	cout << time;
}