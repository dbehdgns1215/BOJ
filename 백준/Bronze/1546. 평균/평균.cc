#include <bits/stdc++.h>
using namespace std;

int main() {
	double score[1002] = {};
	double transfer[1002] = {};

	int n;
	double max = 0.0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}

	// 최댓값 구하기
	for (int j = 0; j < n; j++)
	{
		max = max < score[j] ? score[j] : max;
	}

	// 점수 변환하기
	for (int k = 0; k < n; k++)
	{
		transfer[k] = (score[k] / max) * 100.0;
	}

	// 평균 구하기
	double sum = 0;
	for (int o = 0; o < n; o++)
	{
		sum = sum + transfer[o];
	}
	double average = sum / n;

	cout << average;
}