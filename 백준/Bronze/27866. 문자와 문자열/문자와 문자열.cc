#include <iostream>
#include <string>
using namespace std;

int main() {
    // 단어 S 입력
    string S;
    cin >> S;

    // 정수 i 입력
    int i;
    cin >> i;

    // i번째 글자 출력
    cout << S[i - 1] << endl;

    return 0;
}
