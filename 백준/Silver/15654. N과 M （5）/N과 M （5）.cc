#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
vector<int> nums;

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        bool used = false;
        for (int j = 0; j < k; j++) {
            if (arr[j] == nums[i]) {
                used = true;
                break;
            }
        }
        if (!used) {
            arr[k] = nums[i];
            func(k + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    nums.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 숫자들을 사전 순으로 정렬
    sort(nums.begin(), nums.end());

    // 순열 생성 시작
    func(0);

}
