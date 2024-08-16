#include <bits/stdc++.h>
using namespace std;

int n;
string name[101];
int day[101];
int month[101];
int year[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	vector<tuple<int, int, int, string>> year_month_day;

	for (int i = 0; i < n; i++)
	{
		cin >> name[i];
		cin >> day[i];
		cin >> month[i];
		cin >> year[i];

		year_month_day.push_back({ year[i], month[i], day[i], name[i] });
	}

	sort(year_month_day.begin(), year_month_day.end());

	cout << get<3>(year_month_day[n - 1]) << "\n";
	cout << get<3>(year_month_day[0]) << "\n";


	/*
	추가로 tie를 쓰는 방법

	// 가장 오래된 사람과 가장 최근 사람의 정보를 각각의 변수로 분해
	int oldest_year, oldest_month, oldest_day;
	string oldest_name;
	tie(oldest_year, oldest_month, oldest_day, oldest_name) = year_month_day[0];

	int youngest_year, youngest_month, youngest_day;
	string youngest_name;
	tie(youngest_year, youngest_month, youngest_day, youngest_name) = year_month_day[n - 1];

	// 가장 오래된 사람과 가장 최근 사람의 이름을 출력
	cout << youngest_name << "\n";    // 가장 어린 사람 (마지막)
	cout << oldest_name << "\n";      // 가장 나이 많은 사람 (첫 번째)

	각 개별 요소를 변수에 바인딩해서 코드 가독성 향상 및 연산에 활용 가능.
	*/
}