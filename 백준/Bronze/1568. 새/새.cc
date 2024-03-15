#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; 
    cin >> N; 

    int time = 0; 
    int k = 1; 

    while (N > 0) { // 모든 새가 날아갈 때까지 반복
        if (k > N) { // 날아가야 하는 새의 수가 남아 있는 새의 수보다 많으면
            k = 1; // 1부터 다시 시작
        }
        N -= k; // 날아가야 하는 새의 수만큼 차감
        k += 1; // 다음 숫자 노래 준비
        time += 1; // 시간(초) 증가
    }

    cout << time;
}
