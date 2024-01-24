#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 300000;

int n, m;
int card[MAX_N];
int best_sum = 0;

bool compare(int i, int j)
{
    return j < i;
}

void func(int num, int selected, int current_sum)
{
    if (selected == 3)
    {
        if (current_sum <= m)
        {
            best_sum = max(best_sum, current_sum);
        }
        return;
    }

    for (int i = num; i < n; i++)
    {
        func(i + 1, selected + 1, current_sum + card[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
    }
    sort(card, card + n, compare);

    func(0, 0, 0);

    cout << best_sum;

}
