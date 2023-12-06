#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1		끝값 증가량 -> 6의 배수로 증가	첫값 증가량 -> 6의 배수로 증가
	// 2~7		6								1
	// 8~19		12								6
	// 20~37	18								12
	// 38~61	24								18

	// 끝값을 기준으로 풀이
    int N;
    cin >> N;

    if (N == 1) {
        cout << "1\n";
        return 0;
    }

    int room = 1;
    int range = 2;  // 방 번호의 시작 범위
    int count = 6;  // 현재 범위에서의 방 개수

    while (range <= N) {
        range += count;
        count += 6;
        room++;
    }

    cout << room << "\n";

    return 0;
}