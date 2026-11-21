#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    
    // 1x1 크기의 초콜릿으로 쪼개기 위한 최소 횟수는 (N-1) + (N * (M-1)) 입니다.
    // 즉, 가로 길이 - 1 번의 쪼개기와, 세로 길이 * (가로 길이 - 1) 번의 쪼개기를 합산한 값입니다.
    int minimumBreaks = (N - 1) + (N * (M - 1));
    
    cout << minimumBreaks << endl;
    
}