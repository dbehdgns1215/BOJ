#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int k) {
    if (k == m) // 선택한 숫자가 m개와 일치하면,
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    int start = (k == 0) ? 1 : arr[k - 1]; // 이전 숫자보다 작지 않게 시작
    for (int i = start; i <= n; i++) // k가 0일 때 (최초 시작) -> start가 1부터 시작
    {
        arr[k] = i;
        func(k + 1);
    }
    /*
    main 함수에서 func(0) 호출로 인해서,
    k = 0, start = 1, i = 1 이와 같은 조건을 가지고 종료 조건까지 재귀를 쭉 돌고난 뒤 출력. (이때 출력은 1 x x ...)
    그리고 다시 k = 0인 상태에서 i가 +1 되면서 k = 0, start = 1, i = 2 인 상태로 또 재귀를 돌림. (이때 출력은 2 x x ...)

    다만 여기서 재귀 함수를 호출할 때마다 start의 값이 이전 숫자 arr[k-1]으로 갱신해주면서
    같은 수를 여러번 고를 수 있으면서 서로 중복되는 수열이 없게끔 만들어줌.

    느낌을 이해해보자면, 재귀 함수 호출 -> 선택할 수 있는 영역을 1개 제공해줌. 상태의 제공?
    */
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    func(0);
}
