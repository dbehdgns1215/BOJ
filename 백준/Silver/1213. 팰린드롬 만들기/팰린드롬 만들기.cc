#include <bits/stdc++.h>
using namespace std;

string s;
int arr[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s; // 영어 이름 입력 받기

	for (int i = 0; i < s.size(); i++) {
		arr[s[i] - 65]++; // 영어 이름의 각 스펠링 카운트 처리
	}

	int odd_cnt = 0; // 홀수 개수
	string ans = "";

	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2 == 1) { // 영어 이름에서 스펠링이 '홀수'개 나온 것들 찾음
			odd_cnt++;
			ans += (char)(i + 65); // 빈 ans 문자열에 추가하면 자연스럽게 중앙에 오게 됨
			arr[i]--; // 중앙에 해당 스펠링을 배치하고 하나만큼 감소 -> 해당 스펠링은 다시 짝수개로 변함

			if (odd_cnt > 1) { // 영어 이름에서 스펠링이 '홀수'개 나온 것이 '홀수'개 존재하면 펠린드롬이 될 수 없음
				cout << "I'm Sorry Hansoo";
				exit(0);
			}
		}
	}

	for (int i = 'Z'; i >= 'A'; i--) { // 오름차순으로 정렬하기 위해 Z부터 탐색 시작
		if (arr[(int)i - 65] >= 2) { // 스펠링이 2번 이상 카운트 된 경우 
			while (arr[(int)i - 65] > 0) { // 스펠링이 다 없어질 때까지
				ans = (char)i + ans; // 기존 ans의 왼쪽에 해당 스펠링을 추가
				ans += (char)i; // 추가한 ans의 오른쪽에 해당 스펠링을 다시 추가
				arr[(int)i - 65] -= 2; // 2개만큼 해당 스펠링 카운트 감소
			}
		}
	}

	cout << ans;
}