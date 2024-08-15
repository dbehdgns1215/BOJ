#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int k, l;
unordered_map<string, int> last_pos; // 각 학번의 마지막 등장 위치 저장할 map
vector<pair<int, string>> valid_students; // last_pos와 같이 사용할 위치(int), 학번(string)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> k >> l;

    for (int i = 0; i < l; i++) {
        string id;
        cin >> id;
        last_pos[id] = i;
    }

    for (const auto& entry : last_pos) {
        valid_students.emplace_back(entry.second, entry.first);
    }

    sort(valid_students.begin(), valid_students.end()); // 매개타입이 2개일 때 sort는 first부터 비교하기 때문에 괜찮다

    int cnt = 0;
    for (const auto& student : valid_students) {
        if (cnt == k) break;
        cout << student.second << "\n";
        cnt++;
    }

}