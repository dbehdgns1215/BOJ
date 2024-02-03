#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int X;
    cin >> X;

    int count = 0;
    while (X > 0) {
        if (X % 2 == 1) // X가 홀수라면
            count++;
        X /= 2; // 가장 짧은 막대를 절반으로 자르기
    }

    cout << count;
}
