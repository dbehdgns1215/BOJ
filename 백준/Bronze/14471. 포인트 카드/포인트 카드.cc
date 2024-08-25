#include <bits/stdc++.h>
using namespace std;

vector<int> costs;
int prize_cards = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int Ai, Bi;
        cin >> Ai >> Bi;

        if (Ai >= n) {
            // 이미 경품 교환 가능한 카드
            prize_cards++;
        }
        else {
            // N개 이상의 당첨 도장을 만들기 위한 비용 계산
            costs.push_back(n - Ai);
        }
    }

    // 비용을 오름차순으로 정렬
    sort(costs.begin(), costs.end());

    int required_prize_cards = m - 1;
    int min_cost = 0;

    // 추가로 필요한 경품 교환 가능한 카드 개수만큼 비용을 더해줌
    for (int i = 0; i < required_prize_cards - prize_cards; i++) {
        min_cost += costs[i];
    }

    cout << min_cost << "\n";
    return 0;
}
