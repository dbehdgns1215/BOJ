#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	double time;
	double total_time = 0;
	double score_avg = 0;
	string subject[51];
	string grade;

	for (int i = 0; i < 20; i++)
	{
		cin >> subject[0] >> time >> grade;

		if (grade == "A+") {
			score_avg += time * 4.5;
			total_time += time;
		}
		else if (grade == "A0") {
			score_avg += time * 4.0;
			total_time += time;
		}
		else if (grade == "B+") {
			score_avg += time * 3.5;
			total_time += time;
		}
		else if (grade == "B0") {
			score_avg += time * 3.0;
			total_time += time;
		}
		else if (grade == "C+") {
			score_avg += time * 2.5;
			total_time += time;
		}
		else if (grade == "C0") {
			score_avg += time * 2.0;
			total_time += time;
		}
		else if (grade == "D+") {
			score_avg += time * 1.5;
			total_time += time;
		}
		else if (grade == "D0") {
			score_avg += time * 1.0;
			total_time += time;
		}
		else if (grade == "F") {
			score_avg += time * 0;
			total_time += time;
		}
		else if (grade == "P") {
			continue;
		}
	}

	cout << fixed;
	cout.precision(6);

	cout << score_avg / total_time;
}