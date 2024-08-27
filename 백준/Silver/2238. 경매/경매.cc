#include <bits/stdc++.h>
using namespace std;

int U, N;
vector<int> price_count; // 가격별로 몇 번 제시됐는지 저장
vector<pair<string, int>> v; // 사람과 그 사람이 제시한 가격을 순서대로 저장

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> U >> N;

    price_count.resize(U + 1, 0); // U까지의 가격 범위를 커버하도록 초기화

    for (int i = 0; i < N; ++i) {
        string name;
        int price;
        cin >> name >> price;

        v.emplace_back(name, price);
        price_count[price]++;
    }

    int min_count = N + 1; // 가장 적은 제시 횟수
    int min_price = U + 1; // 최소 가격

    // 가장 적은 수의 사람이 제시한 가격을 찾기
    for (int price = 1; price <= U; price++) {

        // 해당 금액에 대한 제시 횟수가 지금까지의 최소 제시 횟수보다 작으면 최소 제시 횟수 갱신
        if (price_count[price] > 0 && price_count[price] < min_count) {
            min_count = price_count[price];
            min_price = price;
        }
        // 제시 횟수가 같은 경우 제일 작은 금액을 선택.
        else if (price_count[price] == min_count && price < min_price) {
            min_price = price;
        }
    }

    // 위 로직을 거쳤다면 최소 제시 횟수에 대해서 가장 낮은 가격을 보장받을 수 있음.
    
    // 최소 제시 횟수를 가진 가장 낮은 가격을 가장 먼저 제시한 사람을 찾음
    for (const auto& cur : v) {
        if (cur.second == min_price) {
            cout << cur.first << " " << cur.second << endl;
            break;
        }
    }
}
