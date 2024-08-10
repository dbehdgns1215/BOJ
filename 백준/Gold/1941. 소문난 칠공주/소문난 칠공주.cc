#include <bits/stdc++.h>
using namespace std;

int result = 0;
char school[5][5];
bool selected[26];
vector<int> selected_positions;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// BFS로 연결성 체크
bool isConnected() {
    bool visited[5][5] = { false };
    queue<pair<int, int>> q;

    /*
    * 2차원 배열과 1차원 배열의 상호 변환 과정
    * ex) 크기가 3*3인 2차원 배열 arr이 있다고 가정해보자.
    * arr[1][2] 는 
    *  x x x
    *  x x O  -> 이 자리에 위치하게 된다.
    *  x x x
    * 이 2차원 배열을 행 -> 열 순서대로 나열하게 된다면
    *  x x x x x O x x x (arr[5]) 가 되는 것을 알 수 있다.
    * 이를 코드로 표현해본다면
    * int cnt = 0;
    * for (int i = 0; i < 3; i++)
    * {
    *   for (int j = 0; j < 3; j++) {
    *       if (i == 1 && j == 2)
    *       {
    *           return cnt;
    *       }
    *       cnt++;
    *   }
    * }
    * 이렇게하면 2차원 배열에서의 알고자 하는 위치의 인덱스를 1차원 배열로 변환할 수 있다.
    * 위 예제들을 종합적으로 봤을 땐 arr[1][2]는 1차원 arr의 6번째 인덱스(arr[5]) 가 될 것이다.
    * (총 5번의 cnt 증가 후 조건에 걸려서 return)
    * 
    * 반대로 1차원 배열을 2차원 배열로 변환시키려면
    * 2차원 배열의 행에는 1차원 배열을 '2차원 배열의 <행 사이즈>'로 나눈 '몫'을,
    * 2차원 배열의 열에는 1차원 배열을' 2차원 배열의 <열 사이즈>'로 나눈 '나머지'를 대입하면 된다.
    * ex) arr[5]를 크기가 3*3인 2차원 배열로 변환하려면
    * arr[열][행]
    * [열] = arr[5] / 3 -> 1
    * [행] = arr[5] % 3 -> 2
    * -> arr[1][2]
    */

    int x = selected_positions[0] / 5;
    int y = selected_positions[0] % 5;
    q.push({ x, y });
    visited[x][y] = true;
    int connected_count = 1;

    while (!q.empty()) {
        auto cur = q.front(); 
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;

            int pos = nx * 5 + ny; // 1차원 배열 -> 2차원 배열 공식에 의한 로직
            if (!visited[nx][ny] && selected[pos]) { // 방문 X인 해당 학생의 좌표
                visited[nx][ny] = true;
                q.push({ nx, ny });
                connected_count++;
            }
        }
    }

    return connected_count == 7;
}

// 백트래킹을 이용하여 7명을 선택
void backtrack(int idx, int count, int s_count) {
    if (count == 7) {
        if (s_count >= 4 && isConnected()) {
            result++;
        }
        return;
    }

    for (int i = idx; i < 25; i++) {
        if (!selected[i]) {
            selected[i] = true;
            selected_positions.push_back(i);
            backtrack(i + 1, count + 1, s_count + (school[i / 5][i % 5] == 'S' ? 1 : 0));
            selected[i] = false;
            selected_positions.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> school[i][j];
        }
    }

    backtrack(0, 0, 0);

    cout << result;
}
