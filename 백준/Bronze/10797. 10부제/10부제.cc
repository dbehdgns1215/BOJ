#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int date;
    cin >> date;
    int count = 0;
    for(int i = 0; i < 5; i++) {
        int car;
        cin >> car;
        if(car == date) count++;
    }
    cout << count << '\n';
}
