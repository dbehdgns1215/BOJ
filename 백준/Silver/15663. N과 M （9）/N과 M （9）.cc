#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums;
vector<int> sequence;
vector<bool> used;

void func() {
    if (sequence.size() == m) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    int last = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i] && nums[i] != last) {
            used[i] = true;
            sequence.push_back(nums[i]);
            func();
            sequence.pop_back();
            used[i] = false;
            last = nums[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    nums.resize(n);
    used.resize(n, false);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    func();

    return 0;
}