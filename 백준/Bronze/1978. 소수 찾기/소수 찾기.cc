#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int num[100];
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    int prime_count = 0;
    for (int i = 0; i < N; i++) {
        if (num[i] < 2) continue;  // 0과 1은 소수가 아님

        bool is_prime = true;
        for (int j = 2; j * j <= num[i]; j++) {
            if (num[i] % j == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            prime_count++;
        }
    }

    cout << prime_count;

    return 0;
}