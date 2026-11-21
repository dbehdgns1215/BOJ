#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;
	
	list<int> sum;
	int total_sum = 0;
	

	while (k--)
	{
		int i;
		cin >> i;

		sum.push_back(i);
		if (i == 0 && sum.empty() == false)
		{
			sum.pop_back();
			sum.pop_back();
		}
	}
	
	for (const auto& element : sum)
	{
		total_sum += element;
	}

	cout << total_sum;
}