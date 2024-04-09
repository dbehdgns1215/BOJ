#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;

	cin >> k >> n;


	vector <long long> lan(k);
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
	}
    sort(lan.begin(), lan.end());

    long long start = 1; // 최소 길이
    long long end = lan[k - 1]; // 최대 길이
    long long result = 0;

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long count = 0; // 현재 길이로 잘랐을 때 만들 수 있는 랜선의 개수

        for (int i = 0; i < k; ++i) {
            count += lan[i] / mid;
        }

        if (count >= n) { // 더 많이 만들 수 있다면, 길이를 늘려도 됨 -> 목표 count는 n이니까
            result = mid; // 현재 길이 저장
            start = mid + 1;
        }
        else { // 부족하다면, 길이를 줄여야 함
            end = mid - 1;
        }
    }

    cout << result;
}