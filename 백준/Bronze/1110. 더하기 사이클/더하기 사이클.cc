#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int init = N;
    int cnt = 0;

    do {
        int tens = N / 10;
        int ones = N % 10;
        int sum = tens + ones;

        N = ones * 10 + sum % 10;
        cnt++;
    } while (N != init);

    cout << cnt;
}