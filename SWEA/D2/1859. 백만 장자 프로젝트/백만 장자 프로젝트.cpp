#include<bits/stdc++.h>
using namespace std;

int arr[1000001];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		vector<int> prices(N);
		for (int i = 0; i < N; i++) {
			cin >> prices[i];
		}

		long long max_profit = 0; 
		int max_price = 0; 

		for (int i = N - 1; i >= 0; i--) {
			if (prices[i] > max_price) {
				max_price = prices[i];
			}
			else {
				max_profit += max_price - prices[i];
			}
		}
		
        cout << "#" << test_case << " " << max_profit << "\n";
	}
	return 0;
}