#include <bits/stdc++.h>
using namespace std;

// 오른쪽에서 왼쪽으로 쭉 순회하면서 검사하는 방식.
// 처음에는 무조건 제일 오른쪽 인덱스의 값이 스택에 들어가게 되고
// 그 이후부터는 제일 오른쪽의 바로 왼쪽 인덱스에 대해서 스택의 top() 값과 비교
// 
// 만약 해당 인덱스의 값이 스택의 top() 값보다 '작다면', 오큰수가 될 수 있음.
// -> v[2] = 2 (해당 인덱스) v[3] = 7 => s.top() = 7 (스택의 top() 값)
// 
// 그럼 만약 해당 인덱스의 값이 스택의 top() 값보다 '크다면'?
// 해당 인덱스 : 5  top() : 2  -> 오큰수가 될 가능성이 없음.
// 그러므로 스택을 pop하고 다음 스택의 값을 확인.
// 
// 결과적으로는 각 인덱스마다 오큰수 자체를 저장하는 것이기 때문에 가능한 방식.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> nge(n, -1);
    stack<int> s;

    // 수열 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // 뒤에서부터 확인 
    for (int i = n - 1; i >= 0; i--) {
        // 스택에서 현재 원소보다 작은 값들은 모두 제거
        while (!s.empty() && s.top() <= v[i]) {
            s.pop();
        }

        // 스택에 값이 남아있다면 그 값이 현재 원소의 오큰수
        if (!s.empty()) {
            nge[i] = s.top();
        }

        // 현재 원소를 스택에 넣음
        s.push(v[i]);
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }

}
