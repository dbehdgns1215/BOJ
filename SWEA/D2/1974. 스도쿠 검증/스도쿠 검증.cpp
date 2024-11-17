#include <bits/stdc++.h>
using namespace std;

int arr[9][9];

bool checkLine(int arr[9][9]) {
	vector<set<int>> colSets(9);

	for (int i = 0; i < 9; i++) {
		set<int> rowSet;
		for (int j = 0; j < 9; j++) {
			// 행 검사
			if (rowSet.count(arr[i][j])) {
				return false;
			}
			rowSet.insert(arr[i][j]);

			// 열 검사
			if (colSets[j].count(arr[i][j])) {
				return false;
			}
			colSets[j].insert(arr[i][j]);
		}
	}
	return true;
}

bool checkGrid(int arr[9][9]) {
	for (int i = 0; i < 9; i += 3) {
		for (int j = 0; j < 9; j += 3) {
			set<int> gridSet;
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					int num = arr[i + x][j + y];
					if (gridSet.count(num)) {
						return false;
					}
					gridSet.insert(num);
				}
			}
		}
	}
	return true;
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> arr[i][j];
			}
		}

		if (checkLine(arr) && checkGrid(arr)) {
			cout << "#" << test_case << " 1\n";
		}
		else {
			cout << "#" << test_case << " 0\n";
		}
	}
	return 0;
}
