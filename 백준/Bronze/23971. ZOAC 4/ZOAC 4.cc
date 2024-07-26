#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N, M;
    cin >> H >> W >> N >> M;

    int rows = (H / (N + 1)) + (H % (N + 1) != 0 ? 1 : 0);
    int cols = (W / (M + 1)) + (W % (M + 1) != 0 ? 1 : 0);

    cout << rows * cols;
}