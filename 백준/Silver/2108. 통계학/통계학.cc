#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <int> v; 
	int mode[8001] = { 0 }; // 최빈값 전용

	double sum = 0;
	int max = -9999;
	int max_second = 0;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
		sum += temp;
		mode[temp + 4000] ++;
		if (mode[temp + 4000] > max)
		{
			max = mode[temp + 4000]; // 최빈값 갱신
		}
	}
	sort(v.begin(), v.end());

	// 산술평균
	if ((sum / n) > 0)
	{
		cout << (int)((sum / n) + 0.5) << "\n";
	}
	else if ((sum / n) < 0) {
		cout << (int)((sum / n) - 0.5) << "\n";
	}
	else { cout << "0\n"; }

	
	// 중앙값
	cout << v[n / 2] << "\n";

	// 최빈값이 여러개인지 확인
	if (v.size() > 1)
	{
		vector<int> modes;
		for (int i = 0; i <= 8000; i++) {
			if (mode[i] == max) // max는 입력받으면서 일일히 갱신했던 최빈값 (최초의 최빈값이 저장되어있음)
				modes.push_back(i - 4000); // 4000을 더해서 저장했으니 빼줘야 음수도 들어감.
		}

		if (modes.size() == 1)
		{
			cout << modes[0] << "\n";
		}
		else if (modes.size() == 2)
		{
			sort(modes.begin(), modes.end());
			if (modes[0] < modes[1])
			{
				cout << modes[1] << "\n";
			}
			else cout << modes[0] << "\n";
		}
		else
		{
			cout << modes[1] << "\n";
		}

	}
	else { cout << v.back() << "\n"; }

	// 범위
	if (v.size() > 1)
	{
		cout << v.back() - v.front();
	}
	else { cout << "0"; }

}