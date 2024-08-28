#include <bits/stdc++.h>
using namespace std;

string word;
int sum;

void isPrime(int n) {
	bool* isPrime = new bool[n + 1];// n까지 구해야하므로, n+1개를 동적할당

	//먼저 모든 배열을 true로 초기화
	for (int i = 0; i <= n; i++) {
		isPrime[i] = true;
	}


	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {//해당수가 소수라면, 출력하고 해당수를 제외한 배수들을 모두 제외
			cout << i << " ";
			for (int j = i * 2; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> word;
	if (word == "a")
	{
		cout << "It is a prime word.";
		return 0;
	}

	for (int i = 0; i < word.size(); i++)
	{
		if ((int)word[i] > 64 && (int)word[i] < 91)
		{
			sum += ((int)word[i] - 38);
		}
		else if ((int)word[i] > 96 && (int)word[i] < 123)
		{
			sum += ((int)word[i] - 96);
		}
	}

	for (int i = 2; i <= sqrt(sum); i++) { 
		if (sum % i == 0) { 
			cout << "It is not a prime word.";
			return 0;
		}
	}
	cout << "It is a prime word.";

	return 0;
	
}