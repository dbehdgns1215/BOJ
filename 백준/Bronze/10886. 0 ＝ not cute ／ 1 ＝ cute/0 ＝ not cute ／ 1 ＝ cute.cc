#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, vote, cute = 0;
    cin >> N; // 설문조사를 한 사람의 수 입력 받기

    for(int i = 0; i < N; i++) {
        cin >> vote; // 각 사람의 의견 입력 받기
        if(vote == 1) cute++; // '귀엽다'는 의견 카운트
    }

    // '귀엽다'는 의견이 더 많은 경우
    if(cute > N / 2) cout << "Junhee is cute!";
    // '귀엽지 않다'는 의견이 더 많은 경우
    else cout << "Junhee is not cute!";
}
