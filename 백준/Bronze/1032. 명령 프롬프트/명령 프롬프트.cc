#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    
    vector<string> files(N);
    for(int i=0; i<N; i++)
        cin >> files[i];
    
    string pattern = files[0]; // 첫 번째 파일 이름을 패턴으로
    for(int i=1; i<N; i++) { // 나머지 파일 이름과 비교
        for(int j=0; j<pattern.size(); j++) {
            if(pattern[j] != files[i][j]) // 같은 위치에 다른 문자가 있다면
                pattern[j] = '?'; // 패턴을 '?'로 바꿈
        }
    }
    
    cout << pattern; // 패턴 출력

    return 0;
}
