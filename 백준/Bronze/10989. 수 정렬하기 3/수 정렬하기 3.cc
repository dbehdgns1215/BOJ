#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int N, num;
int Count[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        Count[num]++;
    }

    for (int i = 0; i < MAX; i++) {
        while (Count[i]--) {
            cout << i << '\n';
        }
    }
}